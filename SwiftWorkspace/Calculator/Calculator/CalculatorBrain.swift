//
//  CalculatorBrain.swift
//  Calculator
//
//  Created by Siddharth Srinivasan on 8/13/17.
//  Copyright © 2017 Siddharth Srinivasan. All rights reserved.
//

import Foundation

struct CalculatorBrain {
    
    private var accumulator: Double?
    
    private enum Operation {
        case constant(Double)
        case unaryOperation((Double) -> Double)
        case binaryOperation((Double,Double) -> Double)
        case equals
    }
    
    private var operations: Dictionary<String,Operation> = [
        "π": Operation.constant(Double.pi),
        "e": Operation.constant(M_E),
        "√": Operation.unaryOperation(sqrt),
        "cos": Operation.unaryOperation(cos),
        "±":Operation.unaryOperation({-$0}),
        "x" : Operation.binaryOperation({$0 * $1 }),
        "/" : Operation.binaryOperation({$0 / $1 }),
        "+" : Operation.binaryOperation({$0 + $1 }),
        "-" : Operation.binaryOperation({$0 - $1 }),
        "=": Operation.equals
        
    ]
    
    mutating func performOperation(_ symbol: String) {
        if let operation = operations[symbol] {
            switch operation {
            case .constant(let value):
                accumulator = value
            case .unaryOperation(let function):
                if accumulator != nil {
                    accumulator = function(accumulator!)
                }
            case .binaryOperation(let function):
                if accumulator != nil {
                    pendinBinaryOperation = PendingBinaryOperation(function: function, firstOperand: accumulator!)
                    accumulator = nil
                }
            case.equals:
                performPendingBinaryOperation()
            }
        }
    }
    
    private mutating func performPendingBinaryOperation() {
        if pendinBinaryOperation != nil && accumulator != nil {
            accumulator = pendinBinaryOperation!.perform(with: accumulator!)
            pendinBinaryOperation = nil
        }
    }
    
    private var pendinBinaryOperation: PendingBinaryOperation?
    
    private struct PendingBinaryOperation {
        let function: (Double,Double) -> Double
        let firstOperand: Double
        
        func perform(with secondOperand: Double) -> Double {
            return function(firstOperand, secondOperand)
        }
    }
    
    mutating func setOperand(_ operand: Double) {
        accumulator = operand
    }
    
    var result: Double? {
        get {
            return accumulator
        }
    }
}
