// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:srv/AddVariable.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__SRV__DETAIL__ADD_VARIABLE__BUILDER_HPP_
#define CUSTOM_MSGS__SRV__DETAIL__ADD_VARIABLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/srv/detail/add_variable__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace srv
{

namespace builder
{

class Init_AddVariable_Request_b
{
public:
  explicit Init_AddVariable_Request_b(::custom_msgs::srv::AddVariable_Request & msg)
  : msg_(msg)
  {}
  ::custom_msgs::srv::AddVariable_Request b(::custom_msgs::srv::AddVariable_Request::_b_type arg)
  {
    msg_.b = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::srv::AddVariable_Request msg_;
};

class Init_AddVariable_Request_a
{
public:
  Init_AddVariable_Request_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AddVariable_Request_b a(::custom_msgs::srv::AddVariable_Request::_a_type arg)
  {
    msg_.a = std::move(arg);
    return Init_AddVariable_Request_b(msg_);
  }

private:
  ::custom_msgs::srv::AddVariable_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::srv::AddVariable_Request>()
{
  return custom_msgs::srv::builder::Init_AddVariable_Request_a();
}

}  // namespace custom_msgs


namespace custom_msgs
{

namespace srv
{

namespace builder
{

class Init_AddVariable_Response_sum
{
public:
  Init_AddVariable_Response_sum()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_msgs::srv::AddVariable_Response sum(::custom_msgs::srv::AddVariable_Response::_sum_type arg)
  {
    msg_.sum = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::srv::AddVariable_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::srv::AddVariable_Response>()
{
  return custom_msgs::srv::builder::Init_AddVariable_Response_sum();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__SRV__DETAIL__ADD_VARIABLE__BUILDER_HPP_
