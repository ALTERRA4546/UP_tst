package com.example.calc

import android.widget.Button
import android.widget.TextView
import androidx.core.os.persistableBundleOf
import androidx.test.core.app.ActivityScenario
import androidx.test.espresso.Espresso.onView
import androidx.test.ext.junit.rules.ActivityScenarioRule
import androidx.test.platform.app.InstrumentationRegistry
import androidx.test.ext.junit.runners.AndroidJUnit4
import androidx.test.espresso.action.ViewActions.*
import androidx.test.espresso.assertion.ViewAssertions.matches
import androidx.test.espresso.matcher.ViewMatchers.isDisplayed
import androidx.test.espresso.matcher.ViewMatchers.withId
import androidx.test.espresso.matcher.ViewMatchers.withText
import org.hamcrest.Matchers.containsString

import org.junit.Test
import org.junit.runner.RunWith

import org.junit.Assert.*
import org.junit.Rule

/**
 * Instrumented test, which will execute on an Android device.
 *
 * See [testing documentation](http://d.android.com/tools/testing).
 */
@RunWith(AndroidJUnit4::class)
class ExampleInstrumentedTest {
    @get:Rule
    var activity: ActivityScenarioRule<MainActivity> = ActivityScenarioRule(MainActivity::class.java)

    @Test
    fun guessingDice() {
        val message = "1"

        onView(withId(R.id.tvInput)).perform(typeText(message))

        onView(withId(R.id.tvInput)).check(matches(withText(containsString(message))))
    }

    @Test
    fun testDigits() {
        onView(withId(R.id.btn1)).perform(click())
        onView(withId(R.id.btn2)).perform(click())
        onView(withId(R.id.btn1)).check(matches(isDisplayed()));
        onView(withId(R.id.btn2)).check(matches(isDisplayed()));

        onView(withId(R.id.tvInput)).check(matches(withText(containsString("12"))))
    }

    @Test
    fun testAddition() {
        onView(withId(R.id.btn1)).perform(click())
        onView(withId(R.id.btnMultiply)).perform(click())
        onView(withId(R.id.btn2)).perform(click())
        onView(withId(R.id.btnEqual)).perform(click())

        onView(withId(R.id.tvInput)).check(matches(withText(containsString("2"))))
    }

    @Test
    fun testClear() {
        onView(withId(R.id.btn1)).perform(click())
        onView(withId(R.id.btnClear)).perform(click())

        onView(withId(R.id.tvInput)).check(matches(withText(containsString(""))))
    }
}