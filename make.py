import os

def makeit(filename):
    s1 = "gcc "
    s2 = ".c -o "
    s3 = " && "
    return s1+filename+s2+filename+s3+filename

if __name__ == "__main__":
    # print(makeit(input("enter filename: ")))
    os.system(makeit(input("enter filename: ")))
    """
    # this works, too
    # but not as intuitive
    import sys
    os.system(makeit(sys.argv[1]))
    """
    print("success! (from python)")
