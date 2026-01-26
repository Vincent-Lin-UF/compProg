def itop(expr):
    from collections import deque
    out = []
    st = []
    precedence = {'+': 1, '-': 1, '*': 2, '/': 2, '^': 3}
    prev = None
    for ch in expr:
        if ch.isalpha():
            if prev and prev.isalpha():
                return None
            out.append(ch)
        elif ch == "(":
            st.append(ch)
        elif ch == ")":
            found = False
            while st:
                top = st.pop()
                if top == '(':
                    found = True
                    break
                out.append(top)
            if not found:
                return None
        elif ch in precedence:
            if prev is None or prev in precedence or prev == "(":
                return None
            while st and precedence[st[-1]] >= precedence[ch] and ch != "^":
                out.append(st.pop())
            st.append(ch)
        else:
            return None
    
    if prev in precendence:
        return None
    while st:
        if st[-1] == "(":
            return None
        out.append(st.pop())
    return "".join(out)

def solve():
    from sys import stdin
    data = stdin.read().strip().split()
    T = int(data[0])
    exprs = data[1:T+1]
    for e in exprs:
        res = itop(e)
        if res is None:
            print("Invalid Expression")
        else:
            print(res)

if __name__ == "__main__":
    solve()
