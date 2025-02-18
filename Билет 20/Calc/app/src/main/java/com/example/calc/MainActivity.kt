package com.example.calc

import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.TextView
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat


class MainActivity : AppCompatActivity() {
    var resultField: TextView? = null // текстовое поле для вывода результата
    var numberField: EditText? = null // поле для ввода числа
    var operationField: TextView? = null // текстовое поле для вывода знака операции
    var operand: Double? = null // операнд операции
    var lastOperation: String = "=" // последняя операция

    @Override
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        findViewById<Button>(R.id.add).setOnClickListener {
            onOperationClick("+")
        }
        findViewById<Button>(R.id.sub).setOnClickListener {
            onOperationClick("-")
        }
        findViewById<Button>(R.id.mul).setOnClickListener {
            onOperationClick("*")
        }
        findViewById<Button>(R.id.div).setOnClickListener {
            onOperationClick("/")
        }
        findViewById<Button>(R.id.eq).setOnClickListener {
            onOperationClick("=")
        }

        findViewById<Button>(R.id.n0).setOnClickListener {
            onNumberClick("0")
        }
        findViewById<Button>(R.id.n1).setOnClickListener {
            onNumberClick("1")
        }
        findViewById<Button>(R.id.n2).setOnClickListener {
            onNumberClick("2")
        }
        findViewById<Button>(R.id.n3).setOnClickListener {
            onNumberClick("3")
        }
        findViewById<Button>(R.id.n4).setOnClickListener {
            onNumberClick("4")
        }
        findViewById<Button>(R.id.n5).setOnClickListener {
            onNumberClick("5")
        }
        findViewById<Button>(R.id.n6).setOnClickListener {
            onNumberClick("6")
        }
        findViewById<Button>(R.id.n7).setOnClickListener {
            onNumberClick("7")
        }
        findViewById<Button>(R.id.n8).setOnClickListener {
            onNumberClick("8")
        }
        findViewById<Button>(R.id.n9).setOnClickListener {
            onNumberClick("9")
        }
        findViewById<Button>(R.id.comma).setOnClickListener {
            onNumberClick(",")
        }

        resultField = findViewById(R.id.resultField);
        numberField = findViewById(R.id.numberField);
        operationField = findViewById(R.id.operationField);
    }

    override fun onSaveInstanceState(outState: Bundle) {
        outState.putString("OPERATION", lastOperation)
        if (operand != null) outState.putDouble("OPERAND", operand!!)
        super.onSaveInstanceState(outState)
    }

    // получение ранее сохраненного состояния
    override fun onRestoreInstanceState(savedInstanceState: Bundle) {
        super.onRestoreInstanceState(savedInstanceState)
        lastOperation = savedInstanceState.getString("OPERATION")!!
        operand = savedInstanceState.getDouble("OPERAND")
        resultField!!.text = operand.toString()
        operationField!!.text = lastOperation
    }

    // обработка нажатия на числовую кнопку
    fun onNumberClick(number: String?) {
        numberField!!.append(number)
        if (lastOperation == "=" && operand != null) {
            operand = null
        }
    }

    // обработка нажатия на кнопку операции
    fun onOperationClick(op: String) {
        var number = numberField!!.text.toString()
        // если введенно что-нибудь
        if (number.length > 0) {
            number = number.replace(',', '.')
            try {
                performOperation(number.toDouble(), op)
            } catch (ex: NumberFormatException) {
                numberField!!.setText("")
            }
        }
        lastOperation = op
        operationField!!.text = lastOperation
    }

        fun performOperation(number: Double, operation: String) {
            // если операнд ранее не был установлен (при вводе самой первой операции)

            if (operand == null) {
                operand = number
            } else {
                if (lastOperation == "=") {
                    lastOperation = operation
                }
                when (lastOperation) {
                    "=" -> operand = number
                    "/" -> operand = if (number == 0.0) {
                        0.0
                    } else {
                        operand!! / number
                    }

                    "*" -> operand = operand!! * number
                    "+" -> operand = operand!! + number
                    "-" -> operand = operand!! - number
                }
            }
            resultField!!.text = operand.toString().replace('.', ',')
            numberField!!.setText("")
        }

    companion object
    {
        var operand: Double? = null
        var lastOperation: String? = null

        fun performOperation(number: Double, operation: String): Double {

            if (operand == null) {
                operand = number
            } else {
                if (lastOperation == "=") {
                    lastOperation = operation
                }
                when (lastOperation) {
                    "=" -> operand = number
                    "/" -> operand = if (number == 0.0) {
                        0.0
                    } else {
                        operand!! / number
                    }

                    "*" -> operand = operand!! * number
                    "+" -> operand = operand!! + number
                    "-" -> operand = operand!! - number
                }
            }
            lastOperation = operation
            return operand!!
        }

    }
}