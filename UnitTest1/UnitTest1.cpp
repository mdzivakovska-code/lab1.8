#include "pch.h"
#include "CppUnitTest.h"
#include "../lab1.8/Cursor.h"
#include "../lab1.8/Cursor.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab18
{
    TEST_CLASS(UnitTestLab18)
    {
    public:
   
        TEST_METHOD(TestNestedLongLongAdd)
        {
            Cursor::LongLong a = Cursor::LongLong::fromInt64(100);
            Cursor::LongLong b = Cursor::LongLong::fromInt64(30);
            Cursor::LongLong c = a.add(b);

            Assert::AreEqual((long long)130, c.toInt64());
        }

       
        TEST_METHOD(TestCursorSizeValidation)
        {
            Cursor cur;
            Assert::IsTrue(cur.setSize(10));
            Assert::AreEqual(10, cur.getSize());

            Assert::IsFalse(cur.setSize(0));
            Assert::IsFalse(cur.setSize(20));
        }

     
        TEST_METHOD(TestCursorVisibility)
        {
            Cursor cur;
            Cursor::LongLong x = Cursor::LongLong::fromInt64(1);
            Cursor::LongLong y = Cursor::LongLong::fromInt64(1);
            cur.Init(x, y, "horizontal", 5);

            cur.hide();
            Assert::IsFalse(cur.isVisible());

            cur.restore();
            Assert::IsTrue(cur.isVisible());
        }
    };
}