package com.example.calc

import org.junit.Test

import org.junit.Assert.*
import org.junit.Before

/**
 * Example local unit test, which will execute on the development machine (host).
 *
 * See [testing documentation](http://d.android.com/tools/testing).
 */
class ExampleUnitTest {
    @Before
    fun clearData() {
        MainActivity.lastOperation = null
        MainActivity.operand = null
    }

    @Test
    fun operandDiv() {
        MainActivity.performOperation(25.0, "/")
        val result = MainActivity.performOperation(5.0, "=")
        assertEquals(5.0, result, 0.01)
    }

    @Test
    fun operandPlus() {
        MainActivity.performOperation(5.0, "+")
        val result = MainActivity.performOperation(3.0, "=")
        assertEquals(8.0, result, 0.01)
    }
}