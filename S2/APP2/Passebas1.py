# 1/RC*2pi = f0
import numpy as np
import matplotlib.pyplot as plt

# #x = np.abs(np.sin(2*np.pi*f*t)) # sinus redressée.
# x = np.abs(np.sin(2*np.pi*f*t)) # sinus redressée.
# C = 1e-6
# R = 9100
# RC = R*C
# v = (1/RC)*np.exp(-1/RC*t)
# y = np.convolve(x, v)*dt

# T = 10000
# dt = T/10000
# fx = 5000+15
# fy = 5000
# t = np.arange(0, T, dt)
# x = 0.5*np.sin(2*np.pi*fx*t)
# y = 4*np.sin(2*np.pi*fy*t)
# z = x + y

f0 = 15
C = 1.33e-6
R = 1/(2*np.pi*f0*C)

freq  = np.logspace(0, 4, 1000)
omega = 2*np.pi*freq

H = 1 / (1 + 1j*omega*R*C)

phase = np.angle(H, deg=True)
magnitude = 20*np.log10(np.abs(H))
H_10000 = 1 / (1 + 1j * 10000*2*np.pi * R * C)
magnitude10k = 20*np.log10(np.abs(H_10000))

plt.figure()
plt.semilogx(freq, magnitude)
plt.axhline(y=-3, color='r', linestyle='--', label='-3 dB') 
plt.axvline(x=f0, color='r', linestyle='--')
plt.axvline(x=10000, color='y', linestyle='--')
plt.annotate(f'({f0} Hz, -3 dB)', xy=(f0, -3), xytext=(f0*1, -2))
plt.annotate(f'({10000} Hz, {magnitude10k:.2f} dB)', xy=(10000, magnitude10k), xytext=(10000*0.035, magnitude10k))
plt.xlim(0, 20000)
plt.title('Bode - Magnitude de H')
plt.xlabel('Frequence (hz)')
plt.ylabel('Magnitude (dB)')
plt.grid()

plt.figure()
plt.semilogx(freq, phase)
plt.axvline(x=f0, color='r', linestyle='--')
plt.axvline(x=10000, color='y', linestyle='--')
plt.title('Bode - Phase de H')
plt.xlabel('Frequence (hz)')
plt.ylabel('Angle (deg)')
plt.grid()




plt.show()







# plt.figure()
# plt.plot(t, x, "r", label="x")
# plt.plot(t, y, "b", label="y")
# plt.plot(t, z, "g", label="z")
# #plt.plot(t, y[0:len(t)], "b", label="y=x*v")
# plt.axis([0, T, -5, 5])
# plt.grid()
# plt.legend(loc="upper right")
# plt.title('Résultat de la convolution: y=x*v')
# plt.show()


