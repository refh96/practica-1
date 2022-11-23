import tkinter as tk
import tkinter.filedialog as fd
from tkinter import *
from tkinter import ttk
from tkinter import messagebox
import serial ,time



  
def conectar():
    SerialPort.open()
    textbox1.delete(0, END)
    textbox1.insert(0, 'Conectado')
    textbox1.config(bg='lime') 

    messagebox.showinfo(message="puerto conectado ")
    time.sleep(1)
    if( SerialPort.is_open):
     CAD = SerialPort.read_all()
     textbox3.delete(1.0, tk.END)
     textbox3.insert('1.0', CAD)
    
          
def desconectar():
    
    SerialPort.close()
    textbox1.delete(0, tk.END)
    textbox1.insert(0, 'Desconectado')
    textbox1.config(bg='red') 
    textbox3.delete(1.0, tk.END)
    messagebox.showinfo(message="puerto desconectado ")

def enviar():
       tmr = textbox2.get()
       SerialPort.write(tmr.encode())
       SerialPort.write(b"\r")
       messagebox.showinfo(message="Mensaje enviado")
       textbox2.delete(0, tk.END)
       if (SerialPort.is_open):
        textbox3.delete(1.0, tk.END)
        time.sleep(1)
        CAD = SerialPort.read_all()
        textbox3.insert('1.0', CAD)
       
def guardar():
    nuevo_archivo = fd.asksaveasfile(title='Guardar archivo...',
                                     defaultextension='.txt',
                                     filetypes=(('Text files', '*.txt'),))
    if nuevo_archivo:
       contenido = textbox3.get('1.0', tk.END)
       nuevo_archivo.write(contenido)
       nuevo_archivo.close()



def refrescar():
    time.sleep(1)
    CAD = SerialPort.read_all()
    textbox3.insert('1.0', CAD)

def fun():
    SerialPort.close()
    SerialPort.open()
def fun1():
    textbox3.delete(1.0, tk.END)
    SerialPort.write(b"1")
    time.sleep(1)
    CAD = SerialPort.read_all()
    textbox3.insert('1.0', CAD)
def fun2():
    textbox3.delete(1.0, tk.END)
    SerialPort.write(b"2")
    time.sleep(2)
    CAD = SerialPort.read_all()
    textbox3.insert('1.0', CAD)
def fun3():
    textbox3.delete(1.0, tk.END)
    SerialPort.write(b"3")
    time.sleep(2)
    CAD = SerialPort.read_all()
    textbox3.insert('1.0', CAD)
def fun4():
    textbox3.delete(1.0, tk.END)
    SerialPort.write(b"4")
    time.sleep(2)
    CAD = SerialPort.read_all()
    textbox3.insert('1.0', CAD)
def fun5():
    textbox3.delete(1.0, tk.END)
    SerialPort.write(b"5")
    time.sleep(2)
    CAD = SerialPort.read_all()
    textbox3.insert('1.0', CAD)
def fun6():
    textbox3.delete(1.0, tk.END)
    SerialPort.write(b"6")
    time.sleep(2)
    CAD = SerialPort.read_all()
    textbox3.insert('1.0', CAD)
def fun7():
    textbox3.delete(1.0, tk.END)
    SerialPort.write(b"7")
    time.sleep(2)
    CAD = SerialPort.read_all()
    textbox3.insert('1.0', CAD)
def fun8():
    textbox3.delete(1.0, tk.END)
    SerialPort.write(b"8")
    time.sleep(2)
    CAD = SerialPort.read_all()
    textbox3.insert('1.0', CAD)
def fun9():
    textbox3.delete(1.0, tk.END)
    SerialPort.write(b"9")
    time.sleep(2)
    CAD = SerialPort.read_all()
    textbox3.insert('1.0', CAD)
    
ventana = tk.Tk()
ventana.title("Registro")
ventana.geometry("850x550")
ventana.config(background="light grey")
ventana.resizable(0,0)
image= tk.PhotoImage(file="UBB.gif")
image=image.subsample(1,1)
etiqueta=tk.Label(image=image)
etiqueta.place(x=0,y=0)
CAD = tk.StringVar()
tmr = tk.StringVar()
contenido = tk.StringVar()
Button1= tk.Button(ventana, text="Conectar",command=conectar)
Button1.place(x=150, y=70, width=130)
Combo = ttk.Combobox(ventana, state="readonly", values=["COM1","COM2","COM3","COM4","COM5","COM6"])
Combo.place(x=300, y=70, width=130)
Combo.current(2)
SerialPort = serial.Serial(Combo.get(), baudrate=9600)
time.sleep(1)
SerialPort.close()
Button2= tk.Button(ventana, text="Desconectar", command=desconectar)
Button2.place(x=450, y=70, width=130)
textbox1= tk.Entry(ventana, bg="red")
textbox1.place(x=300, y=40, width=100)
ButtonM= tk.Button(ventana, text="Inicio",command=fun,bg='yellow')
ButtonM.place(x=550, y=500, width=130)
Button3= tk.Button(ventana, text="Semaforo",command=fun1)
Button3.place(x=50, y=150, width=130)
Button4= tk.Button(ventana, text="Sensor dht11",command=fun2)
Button4.place(x=50, y=180, width=130)
Button5= tk.Button(ventana, text="paleta de luces",command=fun3)
Button5.place(x=50, y=210, width=130)
Button6= tk.Button(ventana, text="Sensor luminico",command=fun4)
Button6.place(x=50, y=240, width=130)
Button7= tk.Button(ventana, text="Sensor LM35 ",command=fun5)
Button7.place(x=50, y=270, width=130)
Button8= tk.Button(ventana, text="Potenciometro",command=fun6)
Button8.place(x=50, y=300, width=130)
Button9= tk.Button(ventana, text="Switch",command=fun7)
Button9.place(x=50, y=330, width=130)
Button10= tk.Button(ventana, text="Diodo LED",command=fun8)
Button10.place(x=50, y=360, width=130)
Button11= tk.Button(ventana, text="Musica/Buzzer",command=fun9)
Button11.place(x=50, y=390, width=130)
Button12= tk.Button(ventana, text="Cerrar", command=ventana.destroy)
Button12.place(x=50, y=420, width=130)
label1 = tk.Label(ventana, text="Datos enviados")
label1.place(x=250, y=150)
textbox2 = tk.Entry(ventana)
textbox2.place(x=250, y=180, width=150, height=150)
Button10= tk.Button(ventana, text="Enviar", command=enviar)
Button10.place(x=250, y=350, width=130)
label2= tk.Label(ventana, text="Datos Recibidos")
label2.place(x=500, y=150)
label3= tk.Label(ventana, text="Para Volver al menu principal Presione:",bg='yellow')
label3.place(x=300, y=500)
label4= tk.Label(ventana, text="Sensores")
label4.place(x=50, y=120)
textbox3 = tk.Text(ventana, wrap="char",bg='blue')
textbox3.place(x=420, y=180, width=400, height=250)
Button10= tk.Button(ventana, text="Guardar", command=guardar)
Button10.place(x=510, y=440, width=130)
Button11= tk.Button(ventana, text="Actualizar Ventana", command=refrescar, bg='blue')
Button11.place(x=350, y=150, width=130)

ventana.mainloop()