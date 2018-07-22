# _*_ coding: utf-8 _*_
'''
page175 , HMM,NLP汉语自然语言处理原理与实践
'''

import numpy as np
#start matrix
#晴天，阴天，雨天
startp = np.array([0.63,0.17,0.20])

#state-transition matrix
#晴天，阴天，雨天
statep = np.array([[0.5,0.25,0.25],[0.375,0.125,0.375],[0.125,0.625,0.375]])

#emitted matrix
#干旱，干燥，潮湿
emitp = np.array([[0.6,0.20,0.05],[0.25,0.25,0.25],[0.05,0.10,0.50]])

def HMMprobability (emitp,stateEmitinput,n,ob):
    #根据显状态，选择发射概率
    if ob == '干旱':
        emitt = 0
    elif ob == '干燥':
        emitt = 1
    elif ob == '潮湿':
        emitt = 2
    else:
        assert 1==2,'错误的显状态输入'

    stateEmitoutput = statep*stateEmitinput.T  #状态转移矩阵计算：晴天->晴天，雨天，阴天； 雨天->晴天，雨天，阴天；阴天->晴天，雨天，阴天；
    stateEmitoutput = np.sum(stateEmitoutput,axis=1) #计算转移矩阵求和 ，分别为晴天，雨天，阴天的概率
    stateEmitoutput = np.multiply(stateEmitoutput,emitp[:,emitt].T) #发射概率，计算在晴天，雨天，阴天的概率下观察到干旱，干燥，潮湿的概率
    print(stateEmitoutput)
    print('t{0},argmax{1}:{2}'.format(n,n,stateEmitoutput.argmax()))
    return stateEmitoutput

#t1 = 干旱
T1 = np.multiply(startp,emitp[:,0].T)
print(T1)
print('argmax1:{0}'.format(T1.argmax()))
# t3 显状态 干燥
T2 = HMMprobability(emitp,T1,2,'干燥')
# t3 显状态 潮湿
T3 = HMMprobability(emitp,T2,3,'潮湿')



