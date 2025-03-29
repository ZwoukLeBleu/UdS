#Auteurs : Louis-Antoine Gagnon et Zakary Romdhane
import matplotlib.pyplot as plt
import numpy as np
import scipy.signal as signal

import helpers as hp

def filtre_bas():
    R = 4750
    R3 = 4990
    C2 = 100*10**-9
    C3 = 22*10**-9
    
    a = 1
    b = (R+2*R3)/(R*R3*C2)
    c = 1/(R*R3*C2*C3)
    
    k = -c
    z = []
    p = quad(a, b, c)
    
    num, den = signal.zpk2tf(z, p, k)
    
    # hp.bodeplot(num, den, 'Filtre passe-bas: Bode plot', 700)
    z, p, k =signal.butter(2, 700*2*np.pi, 'low', analog=True, output='zpk')
    print("filtre BAS")
    print(np.poly(z))
    print(np.poly(p))
    
    print()
    num, den = signal.zpk2tf(z, p, k)
    hp.pzmap1(z, p, 'Filtre passe-bas: Poles et zeros')
    hp.bodeplot(num, den, 'Filtre passe-bas: Bode plot', 700)
    H = num, den
    return H

def filtre_haut():
    R26 = 10719.67017 #E96 10700, delta=20ohm
    R27 = 48223.94776 #E96 48700, delta=500ohm
    C = 1*10**-9
    
    a = 1
    b = 3/(R27*C)
    c = 1/(R26*R27*C**2)
    
    
    z1 = quad(-1, 0 , 0)
    p1 = quad(a, b, c)
    k1 = 1
    
    num, den = signal.zpk2tf(z1, p1, k1)
    hp.pzmap1(z1, p1, 'Filtre passe-haut: Poles et zeros')
    hp.bodeplot(num, den, 'Filtre passe-haut: Bode plot', 7000)
    z, p, k =signal.butter(2, 7000*2*np.pi, 'high', analog=True, output='zpk')
    print("filtre HAUT")
    # print(np.poly(z))
    # print(np.poly(p))
    print(f"a = {b/2}")
    print(f"b = {b}")
    print(f"c = {c}")
    print(np.arctan((-1*a)/(-1*31149.79))+np.pi/2)
    print()
    
    num, den = signal.zpk2tf(z, p, k)
    hp.bodeplot(num, den, 'Filtre passe-haut: Bode plot', 7000)
    H = num, den
    return H
    
def filtre_bande_bas():
    R = 2870
    R17 = 3320
    C7 = 22*10**-9
    C8 = 4.7*10**-9
    
    a = 1
    b = (R+2*R17)/(R*R17*C7)
    c = 1/(R*R17*C7*C8)
    
    z = []
    p = quad(a, b, c)
    k = -c
    
    num, den = signal.zpk2tf(z, p, k)
    # hp.pzmap1(z, p, 'Filtre passe-bas: Poles et zeros')
    # hp.bodeplot(num, den, 'Filtre passe-bas: Bode plot', 5000)
    # num, den =signal.butter(2, 5000*2*np.pi, 'low', analog=True, output='ba')
    # hp.bodeplot(num, den, 'Filtre passe-bas: Bode plot', 5000)
    z, p, k =signal.butter(2, 5000*2*np.pi, 'low', analog=True, output='zpk')
    print("filtre BANDE-BAS")
    print(np.poly(z))
    print(np.poly(p))
    print()
    num, den = signal.zpk2tf(z, p, k)
    hp.bodeplot(num, den, 'Filtre passe-bande-bas: Bode plot', 5000)
    H = num, den
    return H
    
def filtre_bande_haut():
    R12 = 75 *1000
    R13 = 340 * 1000
    C = 1*10**-9
    
    a = 1
    b = 3/(R13*C)
    c = 1/(R12*R13*C**2)
    
    z1 = quad(-1, 0 , 0)
    p1 = quad(a, b, c)
    k1 = -1
    
    # num, den = signal.zpk2tf(z1, p1, k1)
    # hp.pzmap1(z1, p1, 'Filtre passe-haut: Poles et zeros')
    # hp.bodeplot(num, den, 'Filtre passe-haut: Bode plot', 1000)
    z, p, k =signal.butter(2, 1000*2*np.pi, 'high', analog=True, output='zpk')
    print("filtre BANDE-HAUT")
    print(np.poly(z))
    print(np.poly(p))
    print()
    num, den = signal.zpk2tf(z, p, k)
    hp.bodeplot(num, den, 'Filtre passe-bande-haut: Bode plot', 1000)
    H = num, den
    return H
    
def filtre_bande():
    zl, pl, kl = signal.butter(2, 5000*2*np.pi, 'low', analog=True, output='zpk')
    zh, ph, kh = signal.butter(2, 1000*2*np.pi, 'high', analog=True, output='zpk')
    zf, pf, kf = hp.seriestf(zl, pl, kl, zh, ph, kh)
    num, den = signal.zpk2tf(zf, pf, kf)
    hp.pzmap1(zf, pf, 'Filtre passe-bande: Poles et zeros')
    hp.bodeplot(num, den, 'Filtre passe-bande: Bode plot', 1000)
    
    # w, h = signal.freqs(num, den, worN=[2 * np.pi * 2500])
    # amplitude_response = np.abs(h[0])
    # phase_response = np.angle(h[0])
    
    # input_amplitude = 0.25
    
    # output_amplitude = input_amplitude * amplitude_response
    

    H = num, den
    return H

def quad(a: float, b: float, c: float) :
    x1 = (-b + np.sqrt(b**2 - 4*a*c + 0j))/2
    x2 = (-b - np.sqrt(b**2 - 4*a*c + 0j))/2
    return x1, x2

def test():
    zl, pl, kl =signal.butter(2, 700*2*np.pi, 'low', analog=True, output='zpk')
    zh, ph, kh =signal.butter(2, 7000*2*np.pi, 'high', analog=True, output='zpk')
    zbl, pbl, kbl =signal.butter(2, 5000*2*np.pi, 'low', analog=True, output='zpk')
    zbh, pbh, kbh =signal.butter(2, 1000*2*np.pi, 'high', analog=True, output='zpk')
    zb, pb, kb = hp.seriestf(zbl, pbl, kbl, zbh, pbh, kbh)
    
    zf1, pf1, kf1 = hp.paratf(zl, pl, -kl, zh, ph, -kh)
    G2 = 0.78
    # for i in range(0, 10, 1):
    #     G2 = round((G2 + 0.01), 2)
    zf2, pf2, kf2 = hp.paratf(zf1, pf1, kf1, zb, pb, G2*kb)
    num, den = signal.zpk2tf(zf2, pf2, kf2)
    mag1, ph1, w1, fig, ax = hp.bodeplot(num, den, f"Circuit complet - ", -1)
    delau = - np.diff(ph1) / np.diff(w1)
    hp.grpdel1(w1/2/np.pi, delau, 'Délai de groupe du circuit complet')
    # hp.pzmap1(zf2, pf2, f"Circuit")
    # zf2, pf2, kf2 = hp.paratf(zf1, pf1, kf1, zb, pb, 0.80*kb)


def main():
    HL = filtre_bas()
    # filtre_bande_haut()
    # filtre_bande_bas()
    HH = filtre_haut()
    HB = filtre_bande()
    test()
    # print("\nFonction de transfert passe-bas:")
    # print(HL[0])
    # print(HL[1])
    # print("\nFonction de transfert passe-haut:")
    # print(HH[0])
    # print(HH[1])
    # print("\nFonction de transfert passe-bande:")
    # print(HB[0])
    # print(HB[1])
    # plt.figure()
    # plt.semilogx()
    # plt.axis([20, 30000*2*np.pi, -100, 10])
    # HL_rep = signal.freqs(HL[0], HL[1])
    # HH_rep = signal.freqs(HH[0], HH[1])
    # HB_rep = signal.freqs(HB[0], HB[1])
    # plt.plot(HL_rep[0], 20*np.log10(np.abs(HL_rep[1])), label='Filtre passe-bas')
    # plt.plot(HH_rep[0], 20*np.log10(np.abs(HH_rep[1])), label='Filtre passe-haut')
    # plt.plot(HB_rep[0], 20*np.log10(np.abs(HB_rep[1])), label='Filtre passe-bande')
    
    # mag = 20*np.log10(np.abs(HL_rep[1]*HH_rep[1]*HB_rep[1]))
    # plt.plot(HL_rep[0], mag, label='Filtre combine')
    # # plt.legend()
    # G2 = 0.5
    # for i in range(0, 10, 1):
    #     G2 = G2 + 1/10
    #     HB = G2*HB[0], HB[1]
    #     H = -1*HL + HB + -1*HH
    #     # plt.plot(signal.freqs(H[0], H[1])[0], 20*np.log10(np.abs(signal.freqs(H[0], H[1])[1])), label='G2 = ' + str(G2))
    # plt.figure()
    # plt.semilogx()
    # plt.semilogy()
    # # plt.axis([20, 30000*2*np.pi, -100, 10])
    # plt.axis([20, 30000*2*np.pi, -100, 10])
    
    
    # w, HL_response = signal.freqs(HL[0], HL[1])
    # w, HH_response = signal.freqs(HH[0], HH[1])
    # w, HB_response = signal.freqs(HB[0], HB[1])
    
    # # plt.plot(w, 20*np.log10(np.abs(HL_response)), label='Filtre passe-bas')
    # # plt.plot(w, 20*np.log10(np.abs(HH_response)), label='Filtre passe-haut')
    # # plt.plot(w, 20*np.log10(np.abs(HB_response)), label='Filtre passe-bande')
    
    # G2 = 0.5
    # for i in range(0, 10, 1):
    #     G2 = G2 + 1/10
    #     combined_response = -1*HL_response + G2*HH_response + -1*HB_response
    #     plt.plot(w, 20*np.log10(np.abs(combined_response)), label='G2 = ' + str(G2))
    # # combined_response = -1*HL_response + HH_response + -1*HB_response
    # # plt.plot(w, 20*np.log10(np.abs(combined_response)), label='Filtre combine')
    # plt.legend()
    
    plt.show()
if __name__ == '__main__':
    main()
