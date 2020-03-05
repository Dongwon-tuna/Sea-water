from flask import Flask, render_template,g,Response,make_response

app = Flask(__name__)
app.debug = True

@app.before_request
def before_request():  #used as filter
	print("before request!")
	g.str="Hangeul"

@app.route("/res1")
def res1():
	custom_res = Response("Custom Response",200,{'test':'ttt'})
	return make_response(custom_res)

@app.route("/gg")
def hellow():
	return "hello" + getattr(g,'str','111')

@app.route('/')
def index():
	return render_template('applicaton1.html')


@app.route('/hello/<name>')
def hello(name):
	return render_template('page.html',name=name)


if __name__ == '__main__':
	app.run( host ='0.0.0.0',port=80,debug=True)
