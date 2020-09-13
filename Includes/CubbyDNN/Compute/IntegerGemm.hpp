// Copyright (c) 2020, Jaewoo Kim

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CubbyDNN_COMPUTE_INTEGERGEMM_HPP
#define CubbyDNN_COMPUTE_INTEGERGEMM_HPP
#include <CubbyDNN/Core/Span.hpp>

namespace CubbyDNN::Compute::CPU::Int
{
using namespace Core;

void MultiplyCpu(const Span<int> inputA, const Span<int> inputB,
                 Span<int> out, std::size_t numRowA, std::size_t numColA,
                 std::size_t numRowB, std::size_t numColB,
                 std::size_t numMatrices);

void MultiplyWithBroadcastCpu(const Span<int> inputA, const Span<int> inputB,
                              Span<int> out, std::size_t numRowA,
                              std::size_t numColA, std::size_t numRowB,
                              std::size_t numColB, std::size_t numMatrices,
                              bool broadCastA);

void CpuTranspose(const Span<int> input, Span<int> output,
                  std::size_t numRowInput, std::size_t numColInput,
                  std::size_t batchSize);

void ShrinkCpu(const Span<int> input, Span<int> output, std::size_t size,
               std::size_t batchSize);

void AddCpu(const Span<int> A, const Span<int> B, Span<int> out,
            std::size_t size, std::size_t batchSize);

void SubCpu(const Span<int> A, const Span<int> B, Span<int> out,
            std::size_t size, std::size_t batchSize);

void AddWithBroadcastCpu(const Span<int> A, const Span<int> B, Span<int> out,
                         std::size_t size, std::size_t batchSize,
                         bool broadCastA);

void SubWithBroadcastCpu(const Span<int> A, const Span<int> B, Span<int> out,
                         std::size_t size, std::size_t batchSize,
                         bool broadCastA);
void DotCpu(const Span<int> inputA, const Span<int> inputB, Span<int> out,
            std::size_t size, std::size_t batchSize);

void DotWithBroadcastCpu(const Span<int> inputA, const Span<int> inputB,
                         Span<int> out, std::size_t size, std::size_t batchSize,
                         bool broadCastA);

void DivCpu(const Span<int> inputA, const Span<int> inputB, Span<int> out,
            std::size_t size, std::size_t batchSize);

void DivWithBroadcastCpu(const Span<int> inputA, const Span<int> inputB,
                         Span<int> out, std::size_t size, std::size_t batchSize,
                         bool broadCastA);

void ScalarMulCpu(const Span<int> input, int toMul, Span<int> out,
                  std::size_t size, std::size_t batchSize);

void ScalarDivCpu(const Span<int> input, int toDiv, Span<int> out,
                  std::size_t size, std::size_t batchSize);

void SetCpu(Span<int> data, int toSet, std::size_t size, std::size_t batchSize);
} // namespace CubbyDNN::Compute::CPU::Int

#endif
