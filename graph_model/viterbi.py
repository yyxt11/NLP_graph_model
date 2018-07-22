import numpy as np

startp = { '晴天':0.63,'阴天':0.17,'雨天':0.20}

transp = {'晴天':{'晴天':0.5,'阴天':0.375,'雨天':0.125},
          '阴天':{'晴天':0.25,'阴天':0.125,'雨天':0.625},
          '雨天': {'晴天': 0.25, '阴天': 0.375, '雨天': 0.375}}


emitp = {'晴天':{'干旱':0.60,'干燥':0.2,'潮湿':0.05},
         '阴天': {'干旱': 0.25, '干燥': 0.25, '潮湿': 0.25},
         '雨天': {'干旱': 0.05, '干燥': 0.10, '潮湿': 0.50},}

obs = ('干旱','干燥','潮湿')
states = ('晴天','阴天','雨天')


def viterbi(startp,transp,emitp,obs,states):
    '''
    :param startp: 初始概率
    :param transp: 状态转移概率矩阵，晴天->晴天，雨天，阴天； 雨天->晴天，雨天，阴天；阴天->晴天，雨天，阴天；
    :param emitp: 发射概率矩阵，计算在晴天，雨天，阴天的概率下观察到干旱，干燥，潮湿的显状态概率
    :param obs: 显状态
    :param states: 隐状态
    :return:
    '''
    Vit = [{}]
    for i in range(0, len(obs)):
        statenode = {}
        for s in states:
            # t0,干旱
            if i == 0:
                statenode[s] = startp[s]*emitp[s][obs[0]]
                Vit.append(statenode)
            else:# t1,t2 ......
                statenode[s] = startp[s]*emitp[s][obs[0]]





