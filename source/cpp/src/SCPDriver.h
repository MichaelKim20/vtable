#pragma once

#include <chrono>
#include <functional>
#include <map>
#include <memory>
#include <set>
namespace stellar
{
    class VSCPDriver
    {
        public:
            virtual ~VSCPDriver() {};
            virtual void f1(int value) = 0;
            virtual void f2(int value) = 0;
            void ** getVtable();
    };

    class VTestSCPDriver : public VSCPDriver
    {
        public:
            virtual ~VTestSCPDriver() {};
            void f1(int value);
            void f2(int value);
            void f3(int value);
    };
}
