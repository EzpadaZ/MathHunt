/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Math.h
 * Author: Jorge
 *
 * Created on October 6, 2020, 3:42 PM
 */
#pragma once

#ifndef MATH_H
#define MATH_H

#include <iostream>

struct Vector2f
{
    Vector2f():x(0.0f), y(0.0f)
    {}

    Vector2f(float px, float py):x(px), y(py)
    {}
    
    void print(){
        std::cout <<"X: "<< x << " Y: "<< y << std::endl;
    }
    
    float x, y;
};

#endif /* MATH_H */

