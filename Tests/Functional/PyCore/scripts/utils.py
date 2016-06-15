"""
Collection of utils for testing
"""
import gzip, numpy, sys, os

sys.path.append("@CMAKE_LIBRARY_OUTPUT_DIRECTORY@")

from libBornAgainCore import *


def get_difference(data, reference):
    """
    calculate numeric difference between result and reference data
    """
    reference = reference.reshape(data.shape)
    data -= reference
    diff = 0.0
    epsilon = sys.float_info.epsilon
    for x, y in numpy.ndindex(data.shape):
        v1 = data[x][y]
        v2 = reference[x][y]
        if v1 <= epsilon and v2 <= epsilon:
            diff += 0.0
        elif v2 <= epsilon:
            diff += abs(v1/epsilon)
        else:
            diff += abs(v1/v2)
    diff = diff/data.size
    if numpy.isnan(diff):
        raise Exception("get_difference", "isnan")

    return diff


def get_reference_data(filename):
    """
    read and return reference data from file
    """
    return IntensityDataIOFactory.readIntensityData(
        "@CMAKE_SOURCE_DIR@/Tests/ReferenceData/BornAgain/"+filename)


def get_simulation_MiniGISAS(sample = None):
    simulation = GISASSimulation()
    simulation.setDetectorParameters(25, -2.0*degree, 2.0*degree, 25, 0.0*degree, 2.0*degree)
    simulation.setBeamParameters(1.0*angstrom, 0.2*degree, 0.0*degree)
    if sample:
        simulation.setSample(sample)
    return simulation

def get_simulation_BasicGISAS(sample = None):
    simulation = GISASSimulation()
    simulation.setDetectorParameters(100, 0.0*degree, 2.0*degree, 100, 0.0*degree, 2.0*degree)
    simulation.setBeamParameters(1.0*angstrom, 0.2*degree, 0.0*degree)
    if sample:
        simulation.setSample(sample)
    return simulation

def plot_intensity_data(intensity):
    import matplotlib
    import pylab
    data = intensity.getArray() + 1
    # data = numpy.abs(intensity.getArray())
    phi_min = rad2deg(intensity.getAxis(0).getMin())
    phi_max = rad2deg(intensity.getAxis(0).getMax())
    alpha_min = rad2deg(intensity.getAxis(1).getMin())
    alpha_max = rad2deg(intensity.getAxis(1).getMax())
    im = pylab.imshow(data, norm=matplotlib.colors.LogNorm(),
                      extent=[phi_min, phi_max, alpha_min, alpha_max])
    cb = pylab.colorbar(im)
    cb.set_label(r'Intensity (arb. u.)', size=16)
    pylab.xlabel(r'$\phi_f (^{\circ})$', fontsize=16)
    pylab.ylabel(r'$\alpha_f (^{\circ})$', fontsize=16)
    pylab.show()
