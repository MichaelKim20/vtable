#pragma once

#include <chrono>
#include <functional>
#include <map>
#include <memory>
#include <set>

namespace stellar
{
class SCPDriver
{
public:
    virtual ~SCPDriver();
    virtual void f1(int value);
    virtual void f2(int value);
    void f3(int value);
};
}
