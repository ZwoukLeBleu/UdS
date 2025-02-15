# 2 Spectre (amplitude et phase) de Fourier de l’onde carrée en entrée du filtre;
# 1 Lieux de Bode (gain seulement) en fonction de différentes valeurs de Q. Tracez la courbe qui
# correspond au facteur de qualité choisi avec une couleur distincte.

# D'abord on importe les modules qui seront utilisés
import numpy as np
import matplotlib.pyplot as plt
Vpp = 10  
f = 1000  
T = 1 / f  
dt = 1e-6  
t = np.arange(0, T, dt)  # Time vector for one period
N = len(t)

# Generate the square wave 
x = Vpp * ((t % T) < (T / 2)).astype(float)  # Square wave from 0 to 10V

K = 10  #nbr
Xk_pos = np.zeros(K, dtype=complex) 
nk_pos = np.arange(1, K + 1)  

X0 = (1 / T) * np.sum(x) * dt

for k in nk_pos:
    Xk = (1 / T) * np.sum(x * np.exp(-1j * k * 2 * np.pi * f * t)) * dt
    Xk_pos[k - 1] = Xk

Xk_neg = np.conj(Xk_pos)
Xk_neg = Xk_neg[::-1]  #s
nk_neg = -nk_pos[::-1] 

nk = np.concatenate((nk_neg, [0], nk_pos))
X_k = np.concatenate((Xk_neg, [X0], Xk_pos))

plt.figure()
plt.stem(nk, np.abs(X_k))
plt.axis([0, K, 0, np.max(np.abs(X_k))])
plt.xticks(np.arange(0, 10 + 1, 2))
plt.grid()
plt.title('Fourier - Magnitude')
plt.xlabel('Numero d\'harmonique')
plt.ylabel('Magnitude')

plt.figure()
plt.stem(nk, np.angle(X_k))
plt.xticks(np.arange(-K, K + 1, 2))
plt.grid()
plt.title('Fourier - Phase')
plt.xlabel('Numero d\'harmonique')
plt.ylabel('Phase (radians)')

plt.show()