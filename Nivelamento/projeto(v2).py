class Produto:
  qtde_produtos=0
  produtos=[]
  
  def __init__(self, nome, preco, tipo, qtde):
    self.nome = nome
    self.preco = preco
    self.tipo = tipo
    self.qtde = qtde
    
    
  def save(self):
     Produto.qtde_produtos+=1
     self.id = self.qtde_produtos
     Produto.produtos.append(self)

  def delete():
    Produto.qtde_produtos-=1
     
def inserir():
  qtd = int(input("digite qtde a inserir: "))
  for i in range(qtd):
    nome = input("digite nome do produto: ")
    preco = float(input("digite preço do produto: "))
    tipo = input("digite tipo do produto: ")
    qtde = int(input("digite qtde do produto: "))
    produto = Produto(nome, preco, tipo, qtde)
    produto.save()
  if qtd ==1:
    print("produto inserido")
  else:
    print("produtos inseridos")
  

def alterar():
  achou=0
  qtde = Produto.qtde_produtos
  produtos = Produto.produtos
  nome_alterar=input("digite para alterar: ")
  for i in range(qtde):
    if produtos[i].nome==nome_alterar:
      achou=1
      print("produto encontrado")
      produtos[i].nome = input("digite novo nome do produto: ")
      produtos[i].preco = float(input("digite novo preço do produto: "))
      produtos[i].tipo = input("digite novo tipo do produto: ")
      produtos[i].qtde= int(input("digite nova qtde do produto:  "))
      break
  if achou==0:
    print("produto não encontrado")
    
def pesquisar():
  achou=0
  qtde = Produto.qtde_produtos
  produtos = Produto.produtos
  nome_pesquisar=input("digite para pesquisar: ")
  for i in range(qtde):
    if produtos[i].nome==nome_pesquisar:
      achou=1
      print("produto encontrado")
      print("nome do produto:", produtos[i].nome)
      print("preco do produto:", produtos[i].preco)
      print("tipo do produto:", produtos[i].tipo)
      print("qtde do produto:", produtos[i].qtde)
      break
  if achou==0:
    print("produto não encontrado")

def remover():
  achou=0
  qtde = Produto.qtde_produtos
  produtos = Produto.produtos
  nome_remover=input("digite para remover: ")
  for i in range(qtde):
    if produtos[i].nome==nome_remover:
      achou=1
      del produtos[i]
      Produto.delete()
      print("produto removido")
      break
  if achou==0:
    print("produto não encontrado")
  
def listar():
  qtde = Produto.qtde_produtos
  for i in range(qtde):
    print("produto", i+1)
    print("nome do produto:", Produto.produtos[i].nome)
    print("preco do produto:", Produto.produtos[i].preco)
    print("tipo do produto:", Produto.produtos[i].tipo)
    print("qtde do produto:", Produto.produtos[i].qtde)
  
opcao=0
while opcao!=6:
  if Produto.qtde_produtos==0:
    print("1) inserir")
  else:
    print("1) inserir  2) alterar")
    print("3) pesquisar  4) remover")
    print("5) listar  6) sair")
  opcao=int(input("digite a opção: "))
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