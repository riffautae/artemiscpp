#include "entity.hpp"

#include "entity_manager.hpp"
#include "group_manager.hpp"
#include "tag_manager.hpp"
#include "world.hpp"

#include <sstream>

Entity::Entity(World* world, EntityId id)
{
    this->world_ = world;
    this->entity_manager_ = world_->get_entity_manager();
    this->id_ = id;
}

bool Entity::is_active()
{
    return entity_manager_->isActive(id_);
}

EntityId Entity::get_id()
{
    return id_;
}

EntityId Entity::get_unique_id()
{
    return unique_id_;
}

void Entity::set_unique_id(EntityId unique_id)
{
    this->unique_id_ = unique_id;
}

SystemBits Entity::get_system_bits()
{
    return system_bits_;
}

void Entity::set_system_bits(SystemBits system_bits)
{
    this->system_bits_ = system_bits;
}

ComponentBits Entity::get_comp_bits()
{
    return comp_bits_;
}

void Entity::set_comp_bits(ComponentBits comp_bits)
{
    this->comp_bits_ = comp_bits;
}


///////// other

void Entity::addComponent(ComponentId id)
{
    entity_manager_->addComponent(this, id);
}

void Entity::removeComponent(ComponentId id)
{
    entity_manager_->removeComponent(this, id);
}

Component* Entity::getComponent(ComponentId id)
{
    return entity_manager_->getComponent(this, id);
}

ImmutableBag<Component*>* Entity::getComponents()
{
    return entity_manager_->getComponents(this);
}

void Entity::setGroup(GroupId group)
{
    world_->get_group_manager()->set(group, this);
}

void Entity::setTag(TagId tag)
{
    world_->get_tag_manager()->set(tag, this);
}

std::string Entity::toString()
{
    std::stringstream build;
    build << "Entity[";
    build << id_;
    build << "]";
    std::string ret;
    build >> ret;
    return ret;
}

void Entity::refresh()
{
    world_->refreshEntity(this);
}

void Entity::remove()
{
    world_->deleteEntity(this);
}

void Entity::reset()
{
    system_bits_ = 0;
    comp_bits_ = 0;
} 

void Entity::addSystemId(SystemId id)
{
    system_bits_ |= id;
}

void Entity::removeSystemId(SystemId id)
{
    system_bits_ &= ~id;
}

void Entity::addCompId(ComponentId id)
{
    comp_bits_ |= id;
}

void Entity::removeCompId(ComponentId id)
{
    comp_bits_ &= ~id;
}

