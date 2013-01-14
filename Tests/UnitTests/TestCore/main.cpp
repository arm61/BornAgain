#include "gtest/gtest.h"

#include "BeamTest.h"
#include "ChiSquaredModuleTest.h"
#include "DetectorTest.h"
#include "ExperimentTest.h"
#include "GISASExperimentTest.h"
#include "IParameterizedTest.h"
#include "MaskTest.h"
#include "AxisDoubleTest.h"
#include "OutputDataTest.h"
#include "OutputDataIteratorTest.h"
#include "ParameterPoolTest.h"
#include "RealParameterWrapperTest.h"

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
     return RUN_ALL_TESTS();
}
