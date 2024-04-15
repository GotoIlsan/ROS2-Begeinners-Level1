// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:msg/ListAliveTurtle.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__LIST_ALIVE_TURTLE__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__LIST_ALIVE_TURTLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/msg/detail/list_alive_turtle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_ListAliveTurtle_y
{
public:
  explicit Init_ListAliveTurtle_y(::my_robot_interfaces::msg::ListAliveTurtle & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::msg::ListAliveTurtle y(::my_robot_interfaces::msg::ListAliveTurtle::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::msg::ListAliveTurtle msg_;
};

class Init_ListAliveTurtle_x
{
public:
  explicit Init_ListAliveTurtle_x(::my_robot_interfaces::msg::ListAliveTurtle & msg)
  : msg_(msg)
  {}
  Init_ListAliveTurtle_y x(::my_robot_interfaces::msg::ListAliveTurtle::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_ListAliveTurtle_y(msg_);
  }

private:
  ::my_robot_interfaces::msg::ListAliveTurtle msg_;
};

class Init_ListAliveTurtle_names
{
public:
  Init_ListAliveTurtle_names()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ListAliveTurtle_x names(::my_robot_interfaces::msg::ListAliveTurtle::_names_type arg)
  {
    msg_.names = std::move(arg);
    return Init_ListAliveTurtle_x(msg_);
  }

private:
  ::my_robot_interfaces::msg::ListAliveTurtle msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::msg::ListAliveTurtle>()
{
  return my_robot_interfaces::msg::builder::Init_ListAliveTurtle_names();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__LIST_ALIVE_TURTLE__BUILDER_HPP_
