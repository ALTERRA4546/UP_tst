package com.example.calc

import org.junit.Test

import org.junit.Assert.*

/**
 * Example local unit test, which will execute on the development machine (host).
 *
 * See [testing documentation](http://d.android.com/tools/testing).
 */
class ExampleUnitTest {
    @Test
    fun testAddition() {
        assertEquals(7.0, MainActivity.performOperation("3+4"), 0.0001)
    }

    @Test
    fun testSubtraction() {
        assertEquals(1.0, MainActivity.performOperation("5-4"), 0.0001)
    }

    @Test
    fun testMultiplication() {
        assertEquals(20.0, MainActivity.performOperation("4*5"), 0.0001)
    }

    @Test
    fun testDivision() {
        assertEquals(2.0, MainActivity.performOperation("10/5"), 0.0001)
    }

    @Test
    fun testComplexExpression() {
        assertEquals(14.0, MainActivity.performOperation("2+3*4"), 0.0001)
    }

    @Test
    fun testNegativeNumbers() {
        assertEquals(-1.0, MainActivity.performOperation("-3+2"), 0.0001)
    }

    @Test
    fun testFloatingPointNumbers() {
        assertEquals(7.5, MainActivity.performOperation("3.5+4"), 0.0001)
    }

    @Test
    fun testParentheses() {
        assertEquals(10.0, MainActivity.performOperation("(2+3)*2"), 0.0001)
    }
}