FROM python:3.7

ADD . /code

WORKDIR /code

RUN pip install -r requirements.txt -i https://pypi.tuna.tsinghua.edu.cn/simple

CMD ["/usr/local/bin/python","/code/src/autoConnectNetwork.py"]
