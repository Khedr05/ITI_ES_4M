
def SET_BIT(reg,bit):
    return reg | (1 << bit)

def CLR_BIT(reg, bit):
    return reg & ~(1 << bit)

def TOG_BIT(reg, bit):
    return reg ^ (1 << bit)

def GET_BIT(reg, bit):
    return (reg >> bit) & 1


result = SET_BIT(5, 1)
print(result)  

result = CLR_BIT(7, 1)
print(result)  

result = TOG_BIT(12, 1)
print(result)  

result = GET_BIT(9, 3)
print(result)  
