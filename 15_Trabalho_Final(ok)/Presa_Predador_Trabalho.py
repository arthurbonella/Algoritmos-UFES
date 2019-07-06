#!/usr/bin/env python
# coding: utf-8

# Importação das bibliotecas necessárias
# 
# matplotlib - Biblioteca para gerar gráficos
# 
# scipy - Biblioteca de resolução de cálculos matemáticos

# In[133]:


import matplotlib.pyplot as plt
import scipy as sp


# Representação matemática das Presas

# In[134]:


def fX(x, y, a, b):
    return x * a - b * y * x


# Representação matemática dos Predadores

# In[135]:


def fY(x, y, d, g):
    return y * d * x - y * g


# Instanciação das taxas do animais
# 
# a - Taxa de Reprodução das Presas
# 
# 
# b - Taxa de Sucesso dos Predadores 
# 
# 
# d - Taxa de Reprodução dos Predadores
# 
# 
# g- Taxa de Mortalidade dos Predadores

# In[136]:


a = 0.9990      
b = 0.0035          
d = 0.0030          
g = 0.9000      


# Instanciação do Tempo Inicial e Populações Iniciais (Base Estática)
# 
# t0 - Instante de Tempo Inicial 
# 
# x0 - População Inicial de Presas
# 
# y0 - População Inicial de predadores

# In[137]:


t0 = 0             
x0 = 1200          
y0 = 750


# Instanciação do Tempo e Populações (Base Dinâmica)

# In[138]:


t= t0
x = x0
y = y0


# Resolvendo a equação diferencial usando o método Runge-Kutta de Quarta Ordem
# 
# h - Precisão 
# 
# tempo - Lista com a variação do tempo 
# 
# popX - Lista com a variação de população das presas 
# 
# popY - Lista com a variação de população dos predadores 
# 
# i - Número máximo de repetições

# In[139]:


h = 0.01

tempo = []
popX  = []
popY  = []
i = 1
while (y > 0.0000001) and (x > 0.0000001) and (i < 100000):
    
    k11 = fX(x, y, a, b)
    k12 = fY(x, y, d, g)
    
    t = t + 0.5 * h
    
    k21 = fX(x + h * 0.5 * k11, y + h * 0.5 * k12, a, b)
    k22 = fY(x + h * 0.5 * k11, y + h * 0.5 * k12, d, g)
    
    k31 = fX(x + h * 0.5 * k21, y + h * 0.5 * k22, a, b)
    k32 = fY(x + h * 0.5 * k21, y + h * 0.5 * k22, d, g)
    
    t = t + 0.5 * h
    
    k41 = fX(x + h * k31, y + h * k32, a, b)
    k42 = fY(x + h * k31, y + h * k32, d, g)
    
    x = x + (1.0/6.0) * h * ( 1.0 * k11 + 2.0 * k21 + 2.0 * k31 + 1.0 * k41 )
    y = y + (1.0/6.0) * h * ( 1.0 * k12 + 2.0 * k22 + 2.0 * k32 + 1.0 * k42 )
    i = i + 1
    
    tempo.append(t)
    popX.append(x)
    popY.append(y)


# Representação gráfica

# In[140]:


fig = plt.figure()
plt.title("Representação da Periodicidade entre Presas e Predadores")
plt.plot(popX, popY,'C0',linewidth=2)
plt.xlabel("Numero de Presas")
plt.ylabel("Numero de Predadores")

fig = plt.figure()
plt.title("Relação de População x Tempo")
plt.plot(tempo, popY,'C0',label = "Predadores", linewidth=2)
plt.plot(tempo, popX,'C3',label = "Presas", linewidth=2)
plt.xlabel("Tempo")
plt.ylabel("População")
plt.xlim(0,30)
plt.legend()

plt.show()

