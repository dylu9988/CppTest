
def ret_int():
    return 1001

def AddMulti(a, b):
    return a+b, a*b

def ret_dict():
    ret = {
        "name" : "Robert",
        "ip" : "127.0.0.1",
        "port" : "1024",
        }
    
    return ret

if __name__ == "__main__":
    print("test.py")
    sum, multi = AddMulti(10, 30)
    print("%d, %d" % (sum, multi))

        
        
