import os
import sys
import math

def A(y):
    """Computes and returns the sum of 0 + 1 + 2 + 3 + ... + k + ... + [y/2]"""
    total = 0
    for i in range(int(y/2) + 1):
        total += i
    print("A", total)
    return total

def B(y):
    """Computes the sum of [(y/2)+1] + [((y+1)/2)+1] + [((y+2)/2)+1] + ... [((y+k)/2)+1] + ... + y"""
    total = 0
    for i in range(int(math.floor(y/2)+1), y+1):
        total += i
    print("B", total)
    return total

def main(n = None):
    Total = 0

    # Check for the correct number of command-line arguments
    if n is None:
        print("The program needs one parameter to be executed (e.g., python_script.py 13)")
        sys.exit(0)

    x = n

    # Ensure that the parameter is greater than 0
    if x <= 0:
        print("Unvalid parameter: The parameter should be greater than 0, exiting ...")
        sys.exit(0)

    # Create a child process
    pid = os.fork()
    print("pid=", pid)

    # If the fork failed
    if pid < 0:
        print("Fork system call failed")
        return

    if pid != 0:  # Parent process
        Total += A(x)
        # Total += B(x)
        _, status = os.wait()
        Total += status >> 8 # need to shift status
    else:  # Child process
        os._exit(B(x)) # Ensure the child process terminates here
        # os._exit(A(x))


    # # If this is the parent process, print the total summation
    if pid != 0:
        print(f"The total is: {Total}")
        return Total

if __name__ == "__main__":
    n = 1
    main(n)
    # T = main(1)
    # result = 1
    # n = 1
    # while T == result:
    #     n += 1
    #     result = n * (n+1) / 2
    #     T= main(n)
    #     print(result, T)
    # print("N", n-1)
    
