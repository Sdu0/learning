from flask import Flask
from flask import make_response

app = Flask(__name__)

@app.route('/index')
def index():
    return '<p>Bad Request</p>', 400

@app.route('/index2')
def index2():
    response = make_response('<h1>This document carries a cookie!</h1>')
    response.set_cookie('answer', '42')
    return response

if __name__ == '__main__':
    app.run(debug=True)
