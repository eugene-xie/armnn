//
// Copyright © 2017 Arm Ltd. All rights reserved.
// See LICENSE file in the project root for full license information.
//

#include "Broadcast.hpp"

namespace armnn
{

BroadcastLoop::BroadcastLoop(const TensorShape& inShape0, const TensorShape& inShape1, const TensorShape& outShape)
: m_DimData(outShape.GetNumDimensions())
{
    const unsigned int numDims = GetNumDimensions();

    unsigned int sIn0 = 1;
    unsigned int sIn1 = 1;
    unsigned int sOut = 1;

    for (unsigned int j = numDims - 1, k = 0; k < numDims ; k++, j--)
    {
        m_DimData[j].m_DimSize = outShape[j];
        m_DimData[j].m_Stride1 = (inShape0[j] > 1) ? sIn0 : 0;
        m_DimData[j].m_Stride2 = (inShape1[j] > 1) ? sIn1 : 0;
        m_DimData[j].m_StrideOut = sOut;

        sIn0 *= inShape0[j];
        sIn1 *= inShape1[j];
        sOut *= outShape[j];
    }
}

} // namespace armnn
