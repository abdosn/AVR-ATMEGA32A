#include <gtest/gtest.h>

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../atmega32_mock.h"


// Mock structure to simulate GPIO registers

// Test fixture for GPIO tests
class GPIOTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Initialize the mock GPIO structure to default values
        GPIOA->PIN = 0x00;
        MockGPIOA.DDR = 0x00;
        MockGPIOA.PORT = 0x00;

        MockGPIOB.PIN = 0x00;
        MockGPIOB.DDR = 0x00;
        MockGPIOB.PORT = 0x00;

        MockGPIOC.PIN = 0x00;
        MockGPIOC.DDR = 0x00;
        MockGPIOC.PORT = 0x00;
        
        MockGPIOD.PIN = 0x00;
        MockGPIOD.DDR = 0x00;
        MockGPIOD.PORT = 0x00;
    }

    void TearDown() override {
        // Reset the mock GPIO structure after each test
        MockGPIOA.PIN = 0x00;
        MockGPIOA.DDR = 0x00;
        MockGPIOA.PORT = 0x00;

        MockGPIOB.PIN = 0x00;
        MockGPIOB.DDR = 0x00;
        MockGPIOB.PORT = 0x00;

        MockGPIOC.PIN = 0x00;
        MockGPIOC.DDR = 0x00;
        MockGPIOC.PORT = 0x00;
        
        MockGPIOD.PIN = 0x00;
        MockGPIOD.DDR = 0x00;
        MockGPIOD.PORT = 0x00;
    }
};

// Test case for GPIO_vSetPortDirection
TEST_F(GPIOTest, SetPortDirection_Output) {
    GPIO_vSetPortDirection(&MockGPIOA, OUTPUT);
    EXPECT_EQ(MockGPIOA.DDR, 0xFF);  // All pins should be set as output
}
TEST_F(GPIOTest , SetPortDirectionWithError){

    EXPECT_EXIT(GPIO_vSetPortDirection(&MockGPIOA,(GPIO_Direction_t)3) , ::testing::ExitedWithCode(EXIT_FAILURE) , "");
}
TEST_F(GPIOTest, SetPortDirection_InputFloating) {
    GPIO_vSetPortDirection(&MockGPIOA, INPUT_FLOATING);
    EXPECT_EQ(MockGPIOA.DDR, 0x00);  // All pins should be set as input
    EXPECT_EQ(MockGPIOA.PORT, 0x00); // No pull-up resistors
}

TEST_F(GPIOTest, SetPortDirection_InputPullup) {
    GPIO_vSetPortDirection(&MockGPIOA, INPUT_PULLUP);
    EXPECT_EQ(MockGPIOA.DDR, 0x00);  // All pins should be set as input
    EXPECT_EQ(MockGPIOA.PORT, 0xFF); // Pull-up resistors enabled
}

// Test case for GPIO_vSetPortValue
TEST_F(GPIOTest, SetPortValue_High) {
    GPIO_vSetPortValue(&MockGPIOA, HIGH);
    EXPECT_EQ(MockGPIOA.PORT, 0xFF); // All pins should be set to high
}

TEST_F(GPIOTest, SetPortValue_Low) {
    GPIO_vSetPortValue(&MockGPIOA, LOW);
    EXPECT_EQ(MockGPIOA.PORT, 0x00); // All pins should be set to low
}

// Test case for GPIO_vSetPinDirection
TEST_F(GPIOTest, SetPinDirection_Output) {
    GPIO_vSetPinDirection(&MockGPIOA, Pin3, OUTPUT);
    EXPECT_EQ(MockGPIOA.DDR & (1 << Pin3), (1 << Pin3)); // Pin3 should be set as output
}

TEST_F(GPIOTest, SetPinDirection_InputFloating) {
    GPIO_vSetPinDirection(&MockGPIOA, Pin3, INPUT_FLOATING);
    EXPECT_EQ(MockGPIOA.DDR & (1 << Pin3), 0); // Pin3 should be set as input
    EXPECT_EQ(MockGPIOA.PORT & (1 << Pin3), 0); // No pull-up resistor
}

TEST_F(GPIOTest, SetPinDirection_InputPullup) {
    GPIO_vSetPinDirection(&MockGPIOA, Pin3, INPUT_PULLUP);
    EXPECT_EQ(MockGPIOA.DDR & (1 << Pin3), 0); // Pin3 should be set as input
    EXPECT_EQ(MockGPIOA.PORT & (1 << Pin3), (1 << Pin3)); // Pull-up resistor enabled
}

// Test case for GPIO_vSetPinValue
TEST_F(GPIOTest, SetPinValue_High) {
    GPIO_vSetPinValue(&MockGPIOA, Pin3, HIGH);
    EXPECT_EQ(MockGPIOA.PORT & (1 << Pin3), (1 << Pin3)); // Pin3 should be set to high
}

TEST_F(GPIOTest, SetPinValue_Low) {
    GPIO_vSetPinValue(&MockGPIOA, Pin3, LOW);
    EXPECT_EQ(MockGPIOA.PORT & (1 << Pin3), 0); // Pin3 should be set to low
}

// Test case for GPIO_u8GetPortValue
TEST_F(GPIOTest, GetPortValue) {
    MockGPIOA.PIN = 0xAA; // Simulate input value
    EXPECT_EQ(GPIO_u8GetPortValue(&MockGPIOA), 0xAA); // Should return the same value
}

// Test case for GPIO_u8GetPinValue
TEST_F(GPIOTest, GetPinValue_High) {
    MockGPIOA.PIN = (1 << Pin3); // Simulate Pin3 is high
    EXPECT_EQ(GPIO_u8GetPinValue(&MockGPIOA, Pin3), 1); // Should return 1
}

TEST_F(GPIOTest, GetPinValue_Low) {
    MockGPIOA.PIN = 0x00; // Simulate all pins are low
    EXPECT_EQ(GPIO_u8GetPinValue(&MockGPIOA, Pin3), 0); // Should return 0
}

// Main function for running all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}