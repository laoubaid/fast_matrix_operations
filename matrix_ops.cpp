/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laoubaid <laoubaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:48:17 by laoubaid          #+#    #+#             */
/*   Updated: 2025/07/27 20:21:06 by laoubaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



extern "C" {
    void    mtrx_add_(double *A__, double *B__, double *R__, int rows__, int cols__) {
        int k = 0;
        for (int i = 0; i < rows__; ++i) {
            for (int j = 0; j < cols__; ++j) {
                int tmp = i * cols__ + j;
                R__[k++] = A__[tmp] + B__[tmp];
            }
        }
    }

    void    mtrx_mlt_(double *A__, double *B__, double *R__, int rows__, int cols__) {
        int k = 0;
        for (int i = 0; i < rows__; ++i) {
            for (int j = 0; j < cols__; ++j) {
                int tmp = i * cols__ + j;
                R__[k++] = A__[tmp] * B__[tmp];
            }
        }
    }

    void    mtrx_sub_(double *A__, double *B__, double *R__, int rows__, int cols__) {
        int k = 0;
        for (int i = 0; i < rows__; ++i) {
            for (int j = 0; j < cols__; ++j) {
                int tmp = i * cols__ + j;
                R__[k++] = (A__[tmp] - B__[tmp]);
            }
        }
    }

    void    mtrx_div_(double *A__, double *B__, double *R__, int rows__, int cols__) {
        int k = 0;
        for (int i = 0; i < rows__; ++i) {
            for (int j = 0; j < cols__; ++j) {
                int tmp = i * cols__ + j;
                if (B__[tmp] == 0) {
                    R__[k++] = 0;
                } else {
                    R__[k++] = (A__[tmp] / B__[tmp]);
                }
            }
        }
    }

}
