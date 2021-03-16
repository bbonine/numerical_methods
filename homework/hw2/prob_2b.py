#!/usr/bin/env python
# coding: utf-8

# In[2]:


##############################################
# Problem 2b: Solve the system of equations
#       sin(x+y) = 0
#       cos(x-y) = 0
# Using a canned solver
###############################################


# In[3]:


# Initialize
import numpy as np
from scipy.optimize import fsolve   # for canned solver


# In[17]:


# Set up equations
guess_x = 1
guess_y = 0
def equations(vars):
    x, y = vars
    eq1 = np.sin(x + y)
    eq2 = np.cos(x - y)
    return [eq1, eq2]

x, y =  fsolve(equations, (guess_x, guess_y))

print("For an initial guess of (", guess_x, guess_y, "):")
print("------------------------------------------------")
print("Best guess for x: " + str(x))
print("Best guess for y: " + str(y))


# In[23]:


print (" ")
print(" ")
# Set up equations
guess_x = 2
guess_y = -2
def equations(vars):
    x, y = vars
    eq1 = np.sin(x + y)
    eq2 = np.cos(x - y)
    return [eq1, eq2]

x, y =  fsolve(equations, (guess_x, guess_y))

print("For an initial guess of (", guess_x, guess_y, "):")
print("------------------------------------------------")
print("Best guess for x: " + str(x))
print("Best guess for y: " + str(y))

