import tensorflow as tf
import os
os.environ['TF_CPP_MIN_LOG_LEVEL']='2'

node1 =tf.constant(3.0,tf.float32)
node2 = tf.constant(4.0,tf.float32)
node3 = tf.add(node1,node2)

sess = tf.Session()
print("결과는 이거다:",sess.run(node3))