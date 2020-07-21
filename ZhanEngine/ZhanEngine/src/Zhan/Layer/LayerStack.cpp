#include "zhpch.h"
#include "LayerStack.h"
namespace Zhan {
	/*
					[L, L, L, L, OL]
							     |   | -> emplace_back (overlay)
							     -> m_LayerInsertIndex 
	                 | ->>>>>> Render Layer Order 
					
	*/
	LayerStack::~LayerStack() {
		// Free all the memory held by the vector 
		for (Layer* layer : m_Layers)
		{
			layer->OnDetach();
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer) { 
		// Since emplace create element at index and push the old element at index to the right. 
		// We always make the insert index point to the out-of-bound end of the normal layers (excluding overlay)
	   m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
	   m_LayerInsertIndex++; // after emplace, m_LayerInsertIndex is pointing to the last added layer, insert should be after it 
	}

	void LayerStack::PushOverlay(Layer* overlay) {
		// Overlay is added to the end of the vector, rendered last 
		m_Layers.emplace_back(overlay);
	}

	void LayerStack::PopLayer(Layer* layer) {
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end()) { // if we are not at the end 
			layer->OnDetach();
			m_Layers.erase(it); // remove the layer 
			m_LayerInsertIndex--;
		}
	}

	void LayerStack::PopOverlay(Layer* overlay) {
		auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if (it != m_Layers.end()) { // if overlay exists
			overlay->OnDetach();
			m_Layers.erase(it);  // Do not need to move insert as overlays are all after insert 
		}
	}


}
