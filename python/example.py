# Cheksiz miqdordagi sonlarni qabul qiluvchi funksiya yozing. 
# Funksiya berilgan barcha sonlarning yig‘indisini hisoblab qaytarsin. 
# Agar funksiya chaqirilganda hech qanday son uzatilmasa, natija sifatida 0 qaytarilishi kerak. Funksiyada *args dan foydalanish shart.

# def summ(*lst):
#   if len(lst) == 0:
#     print('Mana shu return ishladi')
#     # return 0

#   for i in range(1, len(lst)):
#     lst[0] += lst[i]

#   print('Ikkinchi return ishladi')
#   # return lst[0]

#   print('Mana shungacha keldi, chunki return yoq')

# print(summ())



def maxn(*args):
  minn= 1_000_000_000
  maxx=-1_000_000_000
  for i in range(len(args)):
    element=args[i]
    if element>maxx:
      maxx=element
    if element<minn:
      minn=element
  print(minn,maxx)
  return (minn,maxx)
  
maxn(2,5,8)




