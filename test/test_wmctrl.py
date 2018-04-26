import unittest
import wmctrl

class WmctrlTester(unittest.TestCase):
    def test_list_windows(self):
        w = wmctr.list_windows()
        self.assertIsInstance(w, list)


if __name__ == "__main__":
    unittest.main()
