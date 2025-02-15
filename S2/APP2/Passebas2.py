#  PT1
#  D'abord on importe les modules qui seront utilisés
import numpy as np
import matplotlib.pyplot as plt
# Q = [1, 2, 5, 10, 15, 20, 25, 30, 35, 40]
# K = 1
# fn = np.arange(0.5, 2, 0.001) # le tableau fn contient les valeurs de f/f0, avec f0 la
# # fréquence centrale. Les valeurs de fn vont de 0,5 à 2 avec un pas de 0,001
# H = -K/(1+1j*Q[0]*(fn-1/fn)) # fonction de transfert H(fn)
# Ha = np.abs(H) # module de la fonction de transfert H
# plt.figure(figsize=(8, 6))
# plt.plot(fn, Ha)
# for ind in np.arange(1, len(Q), 1): # On fait le calcul de H et de son module pour
# #différentes valeurs de Q et on les trace.
#     H = -K / (1 + 1j * Q[ind] * (fn - 1 / fn))
#     Ha = np.abs(H)
#     plt.plot(fn, Ha)

# # PT2
# # gain en dB
# H = -K/(1+1j*Q[0]*(fn-1/fn))
# Ha = abs(H)
# plt.figure(figsize=(8, 6))
# plt.semilogx(fn, 20*np.log10(Ha)) # pour tracer le gain en dB
# for ind in np.arange(1, len(Q), 1):
#     H = -K / (1 + 1j * Q[ind] * (fn - 1 / fn))
#     Ha = abs(H)
#     plt.semilogx(fn, 20 * np.log10(Ha)) # pour tracer le gain en dB
# plt.axis([10**(-0.3), 10**0.3, -40, 0])
# plt.grid()
# plt.show()

T = 0.2
dt = T/10000
f = 2*15
t = np.arange(0, T, dt)
x = np.abs(np.sin(2*np.pi*f*t)) # sinus redressée.
C = 1e-6
R = 15000
RC = R*C
#RC = 1/40
v = (1/RC)*np.exp(-1/RC*t)
y = np.convolve(x, v)*dt
plt.figure()
plt.plot(t, x, "r", label="x")
plt.plot(t, y[0:len(t)], "b", label="y=x*v")
plt.axis([0, T, -1, 2])
plt.grid()
plt.legend(loc="upper right")
plt.title('Résultat de la convolution: y=x*v')
plt.show()

