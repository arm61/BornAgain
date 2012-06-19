#include "LayerInterface.h"

#include <iostream>


LayerInterface::LayerInterface() : m_roughness(0), m_LayerTop(0), m_LayerBottom(0)
{
    setName("interface");
}


LayerInterface::~LayerInterface()
{
    if(m_roughness) delete m_roughness;
}


LayerInterface *LayerInterface::createSmoothInterface(const Layer *p_layer_top, const Layer *p_layer_bottom)
{
    LayerInterface *lr = new LayerInterface();
    lr->setLayerTop(p_layer_top);
    lr->setLayerBottom(p_layer_bottom);
    return lr;
}


LayerInterface *LayerInterface::createRoughInterface(const Layer *p_layer_top, const Layer *p_layer_bottom, const LayerRoughness &roughness)
{
    LayerInterface *lr = new LayerInterface();
    lr->setLayerTop(p_layer_top);
    lr->setLayerBottom(p_layer_bottom);
    lr->setRoughness(roughness);
    return lr;
}


void LayerInterface::setRoughness(const LayerRoughness &roughness)
{
    if(m_roughness) {
        std::cout << "LayerInterface::setRoughness() -> Info. Roughness already assigned to given interface, removing it " << std::endl;
        deregisterChild(m_roughness);
        delete m_roughness;
        m_roughness=0;
    }
    m_roughness = new LayerRoughness(roughness);
    registerChild(m_roughness);
}

