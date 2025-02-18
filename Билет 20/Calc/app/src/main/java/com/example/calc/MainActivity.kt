package com.example.calc

import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {
    lateinit var tvInput: TextView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        tvInput = findViewById(R.id.tvInput)
    }

    fun onDigit(view: View) {
        tvInput.append((view as Button).text)
    }

    fun onClear(view: View) {
        tvInput.text = ""
    }

    fun onOperator(view: View) {
        tvInput.append((view as Button).text)
    }

    fun onEqual(view: View) {
        val tvValue = tvInput.text.toString()
        var result = ""

        try {
            result = performOperation(tvValue).toString()
        } catch (e: Exception) {
            e.printStackTrace()
            result = "Error"
        }

        tvInput.text = result
    }

    companion object {
        fun performOperation(expr: String): Double {
            return object : Any() {
                var pos = -1
                var ch = 0

                fun nextChar() {
                    ch = if (++pos < expr.length) expr[pos].toInt() else -1
                }

                fun eat(charToEat: Int): Boolean {
                    while (ch == ' '.toInt()) nextChar()
                    if (ch == charToEat) {
                        nextChar()
                        return true
                    }
                    return false
                }

                fun parse(): Double {
                    nextChar()
                    val x = parseExpression()
                    if (pos < expr.length) throw RuntimeException("Unexpected: " + ch.toChar())
                    return x
                }

                fun parseExpression(): Double {
                    var x = parseTerm()
                    while (true) {
                        if (eat('+'.toInt())) x += parseTerm()
                        else if (eat('-'.toInt())) x -= parseTerm()
                        else return x
                    }
                }

                fun parseTerm(): Double {
                    var x = parseFactor()
                    while (true) {
                        if (eat('*'.toInt())) x *= parseFactor()
                        else if (eat('/'.toInt())) x /= parseFactor()
                        else return x
                    }
                }

                fun parseFactor(): Double {
                    if (eat('+'.toInt())) return parseFactor()
                    if (eat('-'.toInt())) return -parseFactor()

                    var x: Double
                    val startPos = this.pos
                    if (eat('('.toInt())) {
                        x = parseExpression()
                        eat(')'.toInt())
                    } else if (ch >= '0'.toInt() && ch <= '9'.toInt() || ch == '.'.toInt()) {
                        while (ch >= '0'.toInt() && ch <= '9'.toInt() || ch == '.'.toInt()) nextChar()
                        x = expr.substring(startPos, this.pos).toDouble()
                    } else {
                        throw RuntimeException("Unexpected: " + ch.toChar())
                    }

                    return x
                }
            }.parse()
        }
    }
}
