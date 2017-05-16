# coding: utf8
import sys

from rsa import *

from PyQt4.QtCore import *
from PyQt4.QtGui import *

class Window(QMainWindow):
    def __init__(self):
        super(Window, self).__init__()
        self.setMinimumSize(QSize(300, 250))
        self.setMaximumSize(QSize(300, 250))
        self.setWindowTitle("Asymmetric Encryption")
        self.setWindowIcon(QIcon('pylogo.png'))

        self.paintRadioButtons()
        self.paintLine()
        self.show()

    def paintRadioButtons(self):
        self.font = QFont()
        self.font.setFamily("High Tower Text")
        self.font.setPointSize(20)
        self.font.setBold(False)
        self.font.setItalic(True)
        self.font.setWeight(50)

        self.btn1 = QRadioButton("RSA", self)
        self.btn1.toggled.connect(lambda: self.radio_handler(self.btn1))
        self.btn1.setGeometry(QRect(10, 30, 101, 17)) # QRect(X, Y, Width, Height)
        self.btn1.setFont(self.font)

        self.btn2 = QRadioButton("RSA digital signature", self)
        self.btn2.toggled.connect(lambda: self.radio_handler(self.btn2))
        self.btn2.setGeometry(QRect(10, 80, 251, 31))
        self.btn2.setFont(self.font)

        self.btn3 = QRadioButton("ElGamal", self)
        self.btn3.toggled.connect(lambda: self.radio_handler(self.btn3))
        self.btn3.setGeometry(QRect(10, 150, 121, 17))
        self.btn3.setFont(self.font)

        self.btn4 = QRadioButton("ElGamal digital signature", self)
        self.btn4.toggled.connect(lambda: self.radio_handler(self.btn4))
        self.btn4.setGeometry(QRect(10, 200, 291, 31))
        self.btn4.setFont(self.font)

    def paintLine(self):
        self.line_H = QFrame(self)
        self.line_H.setGeometry(QRect(0, 120, 311, 16))
        self.line_H.setFrameShape(QFrame.HLine)
        self.line_H.setFrameShadow(QFrame.Sunken)

    def radio_handler(self, btn):
        if btn.text() == "RSA":
            if btn.isChecked() == True:
                print btn.text() + " selected"
                #self.setDisabled(True)
                super(Window, self).__init__()
                self.RSA_GUI()
            else:
                print btn.text() + " deselected"

        if btn.text() == "RSA digital signature":
            if btn.isChecked() == True:
                print btn.text() + " selected"
                # self.setDisabled(True)
                super(Window, self).__init__()
                self.RSA_digital_signature_GUI()
            else:
                print btn.text() + " deselected"

        if btn.text() == "ElGamal":
            if btn.isChecked() == True:
                print btn.text() + " selected"
                super(Window, self).__init__()
                self.ElGamal_GUI()
            else:
                print btn.text() + " deselected"

        if btn.text() == "ElGamal digital signature":
            if btn.isChecked() == True:
                # self.setDisabled(True)
                super(Window, self).__init__()
                self.ElGamal_digital_signature_GUI()
                print btn.text() + " selected"
            else:
                print btn.text() + " deselected"

    def RSA_GUI(self):
        self.setWindowTitle("RSA")
        self.setWindowIcon(QIcon('pylogo.png'))
        self.setMinimumSize(QSize(990, 250))
        self.setMaximumSize(QSize(990, 250))

        self.RSA_paintPlainText()
        self.RSA_paintLineEdit()
        self.RSA_paintPushBtns()
        self.RSA_paintLabels()

    def RSA_digital_signature_GUI(self):
        self.setWindowTitle("RSA digital signature")
        self.setWindowIcon(QIcon('pylogo.png'))
        self.setMinimumSize(QSize(990, 250))
        self.setMaximumSize(QSize(990, 250))

        self.RSA_paintPlainText()
        self.RSA_paintLineEdit()
        self.RSA_digital_signature_paintPushBtns()
        self.RSA_paintLabels()

    def RSA_paintPushBtns(self):
        self.font = QFont()
        self.font.setFamily("High Tower Text")
        self.font.setPointSize(14)
        self.font.setItalic(True)
        self.font.setWeight(50)

        self.EncryptButton = QPushButton(self)
        self.EncryptButton.setGeometry(QRect(550, 20, 75, 31))
        self.EncryptButton.setFont(self.font)
        self.EncryptButton.setText("Encrypt")
        self.EncryptButton.clicked.connect(lambda: self.RSA_Encrypt() )

        self.DecryptButton = QPushButton(self)
        self.DecryptButton.setGeometry(QRect(640, 20, 75, 31))
        self.DecryptButton.setFont(self.font)
        self.DecryptButton.setText("Decrypt")
        self.DecryptButton.clicked.connect(lambda: self.RSA_Decrypt() )

    def RSA_digital_signature_paintPushBtns(self):
        self.font = QFont()
        self.font.setFamily("High Tower Text")
        self.font.setPointSize(14)
        self.font.setItalic(True)
        self.font.setWeight(50)

        self.EncryptButton = QPushButton(self)
        self.EncryptButton.setGeometry(QRect(550, 20, 75, 31))
        self.EncryptButton.setFont(self.font)
        self.EncryptButton.setText("Encrypt")
        self.EncryptButton.clicked.connect(lambda: self.RSA_Encrypt() )

        self.DecryptButton = QPushButton(self)
        self.DecryptButton.setGeometry(QRect(640, 20, 75, 31))
        self.DecryptButton.setFont(self.font)
        self.DecryptButton.setText("Decrypt")
        self.DecryptButton.clicked.connect(lambda: self.RSA_Decrypt() )

        self.CheckDigitalSignButton = QPushButton(self)
        self.CheckDigitalSignButton.setGeometry(QRect(730, 20, 150, 31))
        self.CheckDigitalSignButton.setFont(self.font)
        self.CheckDigitalSignButton.setText("Check digital sign")
        self.CheckDigitalSignButton.clicked.connect(lambda: self.RSA_check_digital_sign() )

    def RSA_check_digital_sign(self):
        self.msg_box = QMessageBox()
        self.msg_box.setWindowIcon(QIcon('pylogo.png'))
        self.msg_box.setWindowTitle('Digital sign checking')
        self.msg_box.setIcon(QMessageBox.Information)
        self.msg_box.setStandardButtons(QMessageBox.Ok)

        if self.msg == self.decrypted_msg:
            self.msg_box.setText('Digital sign verified successfully!')
        else:
            self.msg_box.setText('Digital sign crashed!')
        self.msg_box.show()

    def RSA_Encrypt(self):
        self.p = int( self.lineEdit_p.text() )
        self.q = int( self.lineEdit_q.text() )
        self.public, self.private = generate_keypair(self.p, self.q)
        self.msg = self.plainText_MSG.toPlainText()
        self.encrypted_msg_separate = encrypt(self.public, str(self.msg))

        encrypted_msg = ''
        for each in self.encrypted_msg_separate:
            encrypted_msg = encrypted_msg + str(each)
        self.plainTextEdit_Encrypted.setPlainText(str(encrypted_msg))

        print "Your public key is", self.public, "and your private key is", self.private
        print "Your encrypted message is: "
        print self.encrypted_msg_separate

    def RSA_Decrypt(self):
        key, n = self.private
        plain = [chr((char ** key) % n) for char in self.encrypted_msg_separate]
        self.decrypted_msg = ''
        for each in plain:
            self.decrypted_msg = self.decrypted_msg + each
        self.plainTextEdit_Decrypted.setPlainText(self.decrypted_msg)

        print "Decrypting message with private key:"
        print plain

    def RSA_paintLineEdit(self):
        self.font = QFont()
        self.font.setFamily("Times New Roman")
        self.font.setPointSize(14)
        self.font.setWeight(50)

        self.lineEdit_p = QLineEdit(self)
        self.lineEdit_p.setGeometry(QRect(20, 30, 113, 20))
        self.lineEdit_p.setFont(self.font)

        self.lineEdit_q = QLineEdit(self)
        self.lineEdit_q.setGeometry(QRect(170, 30, 113, 20))
        self.lineEdit_q.setFont(self.font)

    def RSA_paintPlainText(self):
        self.font = QFont()
        self.font.setFamily("Times New Roman")
        self.font.setPointSize(14)
        self.font.setWeight(50)

        self.plainText_MSG = QPlainTextEdit(self)
        self.plainText_MSG.setGeometry(QRect(20, 90, 291, 151))
        self.plainText_MSG.setFont(self.font)

        self.plainTextEdit_Encrypted = QPlainTextEdit(self)
        self.plainTextEdit_Encrypted.setGeometry(QRect(350, 90, 291, 151))
        self.plainTextEdit_Encrypted.setFont(self.font)

        self.plainTextEdit_Decrypted = QPlainTextEdit(self)
        self.plainTextEdit_Decrypted.setGeometry(QRect(680, 90, 291, 151))
        self.plainTextEdit_Decrypted.setFont(self.font)

    def RSA_paintLabels(self):
        self.font = QFont()
        self.font.setFamily("High Tower Text")
        self.font.setPointSize(16)
        self.font.setItalic(True)
        self.font.setWeight(50)

        self.label1 = QLabel(self)
        self.label1.setGeometry(QRect(20, 0, 121, 31))
        self.label1.setFont(self.font)

        self.label2 = QLabel(self)
        self.label2.setGeometry(QRect(170, 0, 121, 31))
        self.label2.setFont(self.font)

        self.label3 = QLabel(self)
        self.label3.setGeometry(QRect(300, 10, 241, 41))
        self.label3.setFont(self.font)

        self.label4 = QLabel(self)
        self.label4.setGeometry(QRect(80, 60, 161, 31))
        self.label4.setFont(self.font)

        self.label5 = QLabel(self)
        self.label5.setGeometry(QRect(410, 60, 161, 31))
        self.label5.setFont(self.font)

        self.label6 = QLabel(self)
        self.label6.setGeometry(QRect(740, 60, 281, 31))
        self.label6.setFont(self.font)

        self.label1.setText("Enter p below:")
        self.label2.setText("Enter q below:")
        self.label3.setText("Enter only prime numbers!")
        self.label4.setText("Enter your message:")
        self.label5.setText("Encrypted message:")
        self.label6.setText("Decrypted message:")

        self.show()

    def ElGamal_GUI(self):
        self.setWindowTitle("ElGamal")
        self.setWindowIcon(QIcon('pylogo.png'))
        self.setMinimumSize(QSize(990, 250))
        self.setMaximumSize(QSize(990, 250))

        self.RSA_paintPlainText()
        self.RSA_paintLineEdit()
        self.RSA_paintPushBtns()
        self.RSA_paintLabels()

    def ElGamal_digital_signature_GUI(self):
        self.setWindowTitle("ElGamal digital signature")
        self.setWindowIcon(QIcon('pylogo.png'))
        self.setMinimumSize(QSize(990, 250))
        self.setMaximumSize(QSize(990, 250))

        self.RSA_paintPlainText()
        self.RSA_paintLineEdit()
        self.RSA_digital_signature_paintPushBtns()
        self.RSA_paintLabels()

def main():
    app = QApplication(sys.argv)
    GUI = Window()
    sys.exit(app.exec_())

if __name__ == "__main__":
    main()