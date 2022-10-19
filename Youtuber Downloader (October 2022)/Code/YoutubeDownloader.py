from pytube import YouTube

#Pedir Link
def downloader ():
    youtube=YouTube(link)
    #Titulo del video
    print(f'Title: {youtube.title}')
    #Duración del video
    print(f'Length of video: ({youtube.length//60}:{youtube.length%60})')
    mayor_calidad=youtube.streams.get_highest_resolution()
    mayor_calidad.download('C:\\Users\\HP\\Downloads')
   
link=(input('Link:'))
downloader(link)