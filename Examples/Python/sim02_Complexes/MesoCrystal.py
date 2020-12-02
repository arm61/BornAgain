"""
Cylindrical mesocrystal on a substrate
"""
import bornagain as ba
from bornagain import angstrom, deg, nm, nm2, kvector_t


def get_sample():
    """
    Returns a sample with a cylindrically shaped mesocrystal on a substrate.
    """

    # Define materials
    material_Particle = ba.HomogeneousMaterial("Particle", 0.0006, 2e-08)
    material_Substrate = ba.HomogeneousMaterial("Substrate", 6e-06, 2e-08)
    material_Vacuum = ba.HomogeneousMaterial("Vacuum", 0.0, 0.0)

    # Define form factors
    ff_1 = ba.FormFactorFullSphere(2.0*nm)
    ff_2 = ba.FormFactorCylinder(20.0*nm, 50.0*nm)

    # Define particles
    particle_1 = ba.Particle(material_Particle, ff_1)

    # Define 3D lattices
    lattice = ba.Lattice3D(ba.kvector_t(5.0*nm, 0.0*nm, 0.0*nm),
                           ba.kvector_t(0.0*nm, 5.0*nm, 0.0*nm),
                           ba.kvector_t(0.0*nm, 0.0*nm, 5.0*nm))

    # Define crystals
    crystal = ba.Crystal(particle_1, lattice)

    # Define mesocrystals
    particle_2 = ba.MesoCrystal(crystal, ff_2)

    # Define particle layouts
    layout = ba.ParticleLayout()
    layout.addParticle(particle_2, 1.0)
    layout.setWeight(1)
    layout.setTotalParticleSurfaceDensity(0.01)

    # Define layers
    layer_1 = ba.Layer(material_Vacuum)
    layer_1.addLayout(layout)
    layer_2 = ba.Layer(material_Substrate)

    # Define sample
    sample = ba.MultiLayer()
    sample.addLayer(layer_1)
    sample.addLayer(layer_2)

    return sample


def get_simulation():
    """
    Returns a GISAXS simulation with beam and detector defined
    """
    simulation = ba.GISASSimulation()
    simulation.setDetectorParameters(200, -2.0*deg, 2.0*deg, 200, 0.0*deg,
                                     2.0*deg)
    simulation.setBeamParameters(1.0*angstrom, 0.2*deg, 0.0*deg)
    return simulation


def run_simulation():
    """
    Runs simulation and returns intensity map.
    """
    simulation = get_simulation()
    simulation.setSample(get_sample())
    simulation.runSimulation()
    return simulation.result()


if __name__ == '__main__':
    result = run_simulation()
    ba.plot_simulation_result(result, cmap='jet', aspect='auto')
