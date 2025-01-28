#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

void performOperation(QLineEdit* input, QLabel* resultLabel) {
    QString expression = input->text().remove(" ");  // Remove spaces from the input
    QRegularExpression re(R"(\s*([0-9]+\.?[0-9]*)\s*([\+\-\*\/])\s*([0-9]+\.?[0-9]*)\s*)");
    QRegularExpressionMatch match = re.match(expression);
    if (match.hasMatch()) {
        double num1 = match.captured(1).toDouble();
        char operation = match.captured(2).toLatin1().at(0);
        double num2 = match.captured(3).toDouble();
        double result;
        switch (operation) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/':
            if (num2 != 0)
                result = num1 / num2;
            else {
                resultLabel->setText("Error: Division by zero");
                return;
            }
            break;
        default:
            resultLabel->setText("Error: Invalid operation");
            return;
        }
        resultLabel->setText("= " + QString::number(result));
    } else {
        QRegularExpression num(R"(\s*([0-9]+\.?[0-9]*$))");
        QRegularExpressionMatch isNum = num.match(expression);
        if (isNum.hasMatch())
            resultLabel->setText(isNum.captured(1));
        else
            resultLabel->setText("Syntax error");
    }
    input->setText("");
    input->setFocus();
}

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("Calculator");
    window.setStyleSheet("background-color: #F0F0F0;");

    QLineEdit* input = new QLineEdit(&window);
    input->setAlignment(Qt::AlignRight);
    input->setFixedHeight(50);
    input->setStyleSheet("font-size: 20px; background-color: white; color: black;");

    // Set up the input validator to allow only numbers, operators, dots, and spaces
    QRegularExpression validInput(R"([0-9\+\-\*\/\. ]*)");
    QValidator* validator = new QRegularExpressionValidator(validInput, input);
    input->setValidator(validator);

    QLabel* resultLabel = new QLabel("= ", &window);
    resultLabel->setAlignment(Qt::AlignRight);
    resultLabel->setFixedHeight(50);
    resultLabel->setStyleSheet("font-size: 20px; background-color: #E6E6E6; color: black;");

    QGridLayout* gridLayout = new QGridLayout;
    QStringList buttons = { "7", "8", "9", "/",
                           "4", "5", "6", "*",
                           "1", "2", "3", "-",
                           "0", ".", "=", "+" };

    // Add buttons to the grid layout
    int pos = 0;
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            QString btnText = buttons[pos++];
            QPushButton* button = new QPushButton(btnText, &window);
            button->setFixedSize(60, 60);
            button->setStyleSheet("font-size: 18px; color: black; background-color: #D9D9D9;");
            gridLayout->addWidget(button, row, col);
            QObject::connect(button, &QPushButton::clicked, [=]() {
                if (btnText == "=") {
                    performOperation(input, resultLabel);
                } else {
                    input->setText(input->text() + btnText);
                }
                input->setFocus();
            });
        }
    }

    // Add DEL and AC buttons
    QPushButton* delButton = new QPushButton("DEL", &window);
    delButton->setFixedSize(60, 60);
    delButton->setStyleSheet("font-size: 18px; color: black; background-color: #FFCCCB;");
    gridLayout->addWidget(delButton, 4, 0); // Place DEL button

    QPushButton* acButton = new QPushButton("AC", &window);
    acButton->setFixedSize(60, 60);
    acButton->setStyleSheet("font-size: 18px; color: black; background-color: #FF0000;");
    gridLayout->addWidget(acButton, 4, 1); // Place AC button

    // Connect DEL button functionality
    QObject::connect(delButton, &QPushButton::clicked, [=]() {
        QString text = input->text();
        if (!text.isEmpty()) {
            text.chop(1); // Remove the last character
            input->setText(text);
        }
        input->setFocus();
    });

    // Connect AC button functionality
    QObject::connect(acButton, &QPushButton::clicked, [=]() {
        input->clear(); // Clear the entire input
        resultLabel->setText("= ");
        input->setFocus();
    });

    QVBoxLayout* mainLayout = new QVBoxLayout(&window);
    mainLayout->addWidget(input);
    mainLayout->addWidget(resultLabel);
    mainLayout->addLayout(gridLayout);
    window.setLayout(mainLayout);
    window.resize(350, 450); // Adjusted height to fit the new buttons
    window.show();

    return app.exec();
}
