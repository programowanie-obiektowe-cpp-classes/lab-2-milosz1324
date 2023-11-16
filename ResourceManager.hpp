#pragma once
#include "Resource.hpp"

class ResourceManager {
public:
    ResourceManager() : resource(std::make_shared<Resource>()) {} 
    ~ResourceManager() {}

    double get() {
        if (resource) {
            return resource->get(); 
        }
        else {
            throw std::runtime_error("blad inicializacji");
        }
    }

    ResourceManager(const ResourceManager& other) : resource(other.resource) {}
    ResourceManager& operator=(const ResourceManager& other) {
        if (this != &other) {
            resource = other.resource;
        }
        return *this;
    }

    ResourceManager(ResourceManager&& other) noexcept : resource(std::move(other.resource)) {}
    ResourceManager& operator=(ResourceManager&& other) noexcept {
        if (this != &other) {
            resource = std::move(other.resource);
        }
        return *this;
    }
    
private:
    std::shared_ptr<Resource> resource; // Test wskaźnika inteligentnego
};
