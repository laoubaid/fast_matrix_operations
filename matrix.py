import ctypes

# loading the shared library

lib = ctypes.CDLL("./fastMtrxOps.so")

# Define argtypes and restype for mtrx_add_
op_map = {
    "add": lib.mtrx_add_,
    "sub": lib.mtrx_sub_,
    "mlt": lib.mtrx_mlt_,
    "div": lib.mtrx_div_,
}

for func in op_map.values():
    func.argtypes = [
        ctypes.POINTER(ctypes.c_double),
        ctypes.POINTER(ctypes.c_double),
        ctypes.POINTER(ctypes.c_double),
        ctypes.c_int,
        ctypes.c_int
    ]
    func.restype = None


lib.mtrx_add_.argtypes = [
    ctypes.POINTER(ctypes.c_double),  # first matrix as a flat array
    ctypes.POINTER(ctypes.c_double),  # second matrix as a flat array
    ctypes.POINTER(ctypes.c_double),  # result buffer as a flat array
    ctypes.c_int,                     # rows
    ctypes.c_int                      # cols
]
lib.mtrx_add_.restype = None

def mtrx_op(op, A, B, rows, cols):
    if op not in op_map:
        raise ValueError(f"Unsupported operation: {op}")

    flatA = (ctypes.c_double * (rows * cols))(*[elem for row in A for elem in row])
    flatB = (ctypes.c_double * (rows * cols))(*[elem for row in B for elem in row])
    result = (ctypes.c_double * (rows * cols))()

    op_map[op](flatA, flatB, result, rows, cols)

    return [list(result[i*cols:(i+1)*cols]) for i in range(rows)]

# Example usage
A = [[1.0, 2.0], [3.0, 4.0]]
B = [[5.0, 6.0], [7.0, 8.0]]

print("A: ", A)
print("B: ", B)
print("addition         : ", mtrx_op("add", A, B, 2, 2))
print("subtraction      : ", mtrx_op("sub", A, B, 2, 2))
print("multiplication   : ", mtrx_op("mlt", A, B, 2, 2))
print("division         : ", mtrx_op("div", A, B, 2, 2))