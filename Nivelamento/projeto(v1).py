nomes=[]
precos=[]
tipos=[]
qtdes=[]
total=0

def inserir():
  qt=int(input("qtde a inserir: "))
  global total
  total+=qt
  for i in range(qt):
    nome=input("digite nome do produto: ")
    nomes.append(nome)
    preco=float(input("digite preco do produto: "))
    precos.append(preco)
    tipo=input("digite tipo do produto: ")
    tipos.append(tipo)
    qtde=int(input("digite qtde do produto: "))
    qtdes.append(qtde)
  if qt==1:
    print("produto inserido")
  else:
    print("produtos inseridos")

def alterar():
  achou=0
  nome_alterar = input("nome para alterar: ")
  for nome in nomes:
    if nome==nome_alterar:
      print("produto encontrado")
      achou=1
      i = nomes.index(nome)
      nomes[i] = input("digite novo nome do produto: ")
      precos[i] = int(input("digite novo preco do produto: "))
      tipos[i] = input("digite novo tipo do produto: ")
      qtdes[i] = int(input("digite nova qtde do produto: "))
      break
  if achou==0:
    print("produto não encontrado")
       
def pesquisar():
  achou=0
  nome_pesquisar = input("nome para pesquisar: ")
  for nome in nomes:
    if nome==nome_pesquisar:
      print("produto encontrado")
      achou=1
      i = nomes.index(nome)
      print("nome do produto:", nomes[i])
      print("preco do produto:", precos[i])
      print("tipo do produto:", tipos[i])
      print("qtde do produto:", qtdes[i])
      break
  if achou==0:
    print("produto não encontrado")
    
def remover():
  achou=0
  global total
  nome_remover = input("digite para remover: ")
  for nome in nomes:
    if nome==nome_remover:
      achou=1
      total-=1
      i= nomes.index(nome)
      nomes.pop(i)
      precos.pop(i)
      tipos.pop(i)
      qtdes.pop(i)
      print("produto removido")
      break
  if achou==0:
    print("produto não encontrado")
  
def listar():
  global total
  for i in range(total):
    print("produto", i+1)
    print("nome do produto:", nomes[i])
    print("preco do produto:", precos[i])
    print("tipo do produto:", tipos[i])
    print("qtde do produto:", qtdes[i])
      
opcao=1
while opcao!=6:
  if total==0:
    print("1) inserir")
  else:
    print("1) inserir  2) alterar")
    print("3) pesquisar  4) remover")
    print("5) listar  6) sair")
  opcao=int(input("-> digite opção: "))
  if opcao==1:
    inserir()
  elif opcao==2:
    alterar()
  elif opcao==3:
    pesquisar()
  elif opcao==4:
    remover()
  elif opcao==5:
    listar()
