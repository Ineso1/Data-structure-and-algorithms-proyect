class Tree(object):
  def __init__(self, x):
    self.value = x
    self.left = None
    self.right = None

def preorder(t):
    res = ""
    if t.left:
        lv = preorder(t)
        res += lv
    if t.right:
        rv = preorder(t)
        res += rv
    return res + t.value


def solution(t1, t2):
    print(preorder(t1))



if __name__ == '__main__':
    t1 = {
    "value": 5,
    "left": {
        "value": 10,
        "left": {
            "value": 4,
            "left": {
                "value": 1,
                "left": None,
                "right": None
            },
            "right": {
                "value": 2,
                "left": None,
                "right": None
            }
        },
        "right": {
            "value": 6,
            "left": None,
            "right": {
                "value": -1,
                "left": None,
                "right": None
            }
        }
    },
    "right": {
        "value": 7,
        "left": None,
        "right": None
    }
}
    solution(t1,t1)