/*
 * Tensor1.h
 * @brief Rank 1 tensors based on http://www.gps.caltech.edu/~walter/FTensor/FTensor.pdf
 * Created on: Feb 10, 2010
 * @author: Frank Dellaert
 */

#pragma once
#include "tensors.h"

namespace tensors {

	/** A rank 1 tensor. Actually stores data. */
	template<int N>
	class Tensor1 {
		double T[N];

	public:

		/** default constructor */
		Tensor1() {
		}

		/** construct from data */
		Tensor1(const double* data) {
			for (int i = 0; i < N; i++)
				T[i] = data[i];
		}

		/** construct from expression */
		template<class A, char I>
		Tensor1(const Tensor1Expression<A, Index<N, I> >& a) {
			for (int i = 0; i < N; i++)
				T[i] = a(i);
		}

		/** return data */
		inline int dim() const {
			return N;
		}

		/** return data */
		inline const double& operator()(int i) const {
			return T[i];
		}

		/** return data */
		inline double& operator()(int i) {
			return T[i];
		}

		/* return an expression associated with an index */
		template<char I> Tensor1Expression<Tensor1, Index<N, I> > operator()(Index<
				N, I> index) const {
			return Tensor1Expression<Tensor1, Index<N, I> > (*this);
		}

	}; // Tensor1

} // namespace tensors
