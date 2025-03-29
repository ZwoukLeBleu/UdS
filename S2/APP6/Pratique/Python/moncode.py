import helpers as hp
import numpy as np
import matplotlib.pyplot as plt
import scipy.signal as signal

def q1():
    print("--- Q1 ---")
    w = np.linspace(0.1, 1000, 1000)
    s = (0 + 1j*w)
    H1 = 100/(s+100)
    H2 = (s*s)/(s*s + 141*s + 100*100)
    HP = H1+H2
    plt.figure()
    plt.title("module")
    plt.semilogx()
    mod = np.abs(HP)
    plt.plot(w, mod)
    
    plt.figure()
    plt.title("angle")
    plt.semilogx()
    phase = np.angle(HP)
    plt.plot(w, phase)
    
    plt.figure()
    plt.title("delay")
    delay = -np.diff(phase)/np.diff(w)
    plt.semilogx()
    plt.plot(w[0:-1], delay)
    
    # --- 1b ---
    t = np.linspace(0, 0.200, 1000)
    x = 1*np.sin(100*t + 0)
    
    
    
def q2():
    # --- 2a ---
    print("--- Q2 ---")
    num = [1, 1, 1]
    den = [1, -1, 4]
    z, p, k = signal.tf2zpk(num, den)
    hp.pzmap1(z, p, '2a')
    
    # --- 2b ---
    pn = []
    for i in p:
        pn.append(complex(-i.real, i.imag))
    hp.pzmap1(z, pn, '2b')
    
    # --- 2c ---
    w, mag, phase = signal.bode((num, den), w=np.logspace(1,3,1000))
    angle = np.deg2rad(phase)
    delay = -np.diff(angle)/np.diff(w)
    hp.grpdel1(w, -delay/2, '2c')
    # plt.axis([0, 1000, 0, 0.0010])
    plt.semilogx()
    
def q3():
    # --- 3a ---
    z = [(-2 + 2*1j), (-2 - 2*1j)]
    p = [(-2 + 1j), (-2 - 1j)]
    
    # num, den = signal.zpk2tf(z, p, 1)
    num = np.poly(z)
    den = np.poly(p)
    
    # --- 3b --- 
    
def q3b(w: float):
    z = [(-2 + 2*1j), (-2 - 2*1j)]
    p = [(-2 + 1j), (-2 - 1j)]
    num = np.poly(z)
    den = np.poly(p)
    H = ((-2 + 2*1j)*(-2 - 2*1j))/((-2 + 1j)*(-2 - 1j))
    
    
def main():
    # q1()
    q2()
    # q3()
    plt.show()
    
if __name__ == "__main__":
    main()