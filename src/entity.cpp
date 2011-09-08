#include <sstream>

#include "entity.h"

Entity::Entity(World world, int id)
{
    this->world_ = world;
    this->entity_manager_ = world.get_entity_manager();
    this->id_ = id;
}

bool Entity::is_active()
{
    return entity_manager.isActive(id_);

int Entity::get_id()
{
    return id_;
}

long Entity::get_unique_id()
{
    return unique_id_;
}

void Entity::set_unique_id(long unique_id)
{
    this->unique_id_ = unique_id;
}

long Entity::get_system_bits()
{
    return system_bits_;
}

void Entity::set_system_bits(long system_bits)
{
    this->system_bits_ = system_bits;

long Entity::get_type_bits()
{
    return type_bits_;
}

void Entity::set_type_bits(long type_bits)
{
    this->type_bits_ = type_bits;
}


///////// other

void Entity::addComponent(Component* component)
{
    entity_manager_.addComponent(*this, component);
}

void Entity::addComponent(ComponentName name)
{
    entity_manager_.addComponent(*this, name);

void Entity::removeComponent(Component* component)
{
    entity_manager_.removeComponent(*this, component);
}

void Entity::removeComponent(ComponentType* type)
{
    entity_manager_.removeComponent(*this, type);
}

void Entity::removeComponent(ComponentName name)
{
    entity_manager_.removeComponent(*this, name);
}

Component Entity::getComponent(ComponentType* type)
{
    return entity_manager_.getComponent(*this, type);
}

Component Entity::getComponent(ComponentName name)
{
    return entity_manager_.getComponent(*this, name);
}

ImmutableBag<Component C> Entity::getComponents()
{
    return entity_manager_.getComponents(*this);
}

void Entity::setGroup(std::string group)
{
    world_.get_group_manager().set(group, this);
}

void Entity::setTag(std::string tag)
{
    world_.get_group_manager().set(tag, this);
}

void Entity::setTag(std::string tag)
{
    world_.get_tag_manager().register(tag, this);
    world_.get_tag_manager().register(tag, this);

std::string Entity::toString()
{
    std::stringstream build;
    build << "Entity[";
    build << id;
    build << "]";
    std::string ret;
    build >> ret;
    return ret;
}

void Entity::refresh()
{
    world_.refreshEntity(this);
}

void Entity::remove()
{
    world_.deleteEntity(this);
}

void Entity::reset()
{
    system_bits_ = 0;
    type_bits_ = 0;
} 

void Entity::addSystemBit(long bit)
{
    system_bits_ |= bit;
}

void Entity::removeSystemBit(long bit)
{
    system_bits_ &= ~bit;
}

void Entity::addTypeBit(long bit)
{
    type_bits_ |= bit;
}

void Entity::removeTypeBit(long bit)
{
    type_bits_ &= ~bit;
}

