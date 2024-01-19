-- Definindo o tipo de dados do aluno
type StudentID = Int 
type FirstName = String 
type LastName = String 
type Age =  Int 

-- Definindo um tipo de dados Student 
type Student = (StudentID, FirstName, LastName,Age)

-- Banco de dados inicial de estudantes 
initialDatabase:: [Student]
initialDatabase = []

-- Função para adicionar estudante à base de dados 
adicionarStudent :: [Student]-> IO [Student]
adicionarStudent alunos = do
    putStrLn "\nDigite o ID do estudante:"
    num <- readLn :: IO StudentID 

    -- Verificação se o ID já esta adicionado 
    if alunoJaCadastrado num alunos
        then do
            putStrLn "ID já cadastrado! Tente novamente."
            return alunos
        else do 
            putStrLn "Digite o primeiro nome do estudante:"
            nome <- getLine :: IO FirstName 
            putStrLn "Digite o sobrenome do estudante:"
            sobrenome <- getLine :: IO LastName
            putStrLn "Digite a idade do estudante:"
            idade <- readLn :: IO Age

            if idade <= 0
                then do 
                    putStrLn "\nA idade deve ser um numero positivo! Tente novamente"
                    return alunos 
                else do
                    let novoStudent = (num, nome, sobrenome, idade)
                    putStrLn "\nEstudante adicionado com sucesso no banco de dados!"
                    return (novoStudent : alunos)

-- Verificando se o ID está ja esta no sistema
alunoJaCadastrado :: StudentID -> [Student] -> Bool
alunoJaCadastrado _ [] = False 
alunoJaCadastrado num ((id, _, _, _) : alunosRestantes) = 
        if num == id 
        then True 
        else alunoJaCadastrado num alunosRestantes

-- Função para filtrar estudantes por ID 
filtrarStudent:: [Student] -> IO()
filtrarStudent aluno = do
    putStrLn "\nInforme o ID do estudade que deseja buscar:"
    num <- readLn
    let estudanteEncontrado = filter(\(id,_,_,_) -> id == num) aluno
    case estudanteEncontrado of 
        [] -> putStrLn "\nNenhum estudante encontrado com o ID informado!"
        [(id, nome, sobrenome, idade)] -> do
            putStrLn "\n----------------------"
            putStrLn "Estudante Encontrado!"
            putStrLn "----------------------"
            putStrLn ("ID: " ++ show id)
            putStrLn ("Nome: " ++ show nome)
            putStrLn ("Sobrenome: " ++ show sobrenome)
            putStrLn ("Idade: " ++ show idade)
            putStrLn "----------------------\n"

-- Função para atualizar o cadastro de uma pessoa
atualizaCadastro :: StudentID -> (FirstName, LastName, Age) -> [Student] -> [Student]
atualizaCadastro num (attFirstName, attLastName, attAge) alunos =
    if alunoJaCadastrado num alunos
        then map (\(id, _, _, _) -> (id, attFirstName, attLastName, attAge)) (filter (\(id, _, _, _) -> id == num) alunos)
        else alunos  -- Se o aluno não está cadastrado, retorna o banco de dados sem alterações

-- Interface do menu
-- Interface do menu
menu :: [Student] -> IO()
menu x = do 
    putStrLn "\n --------------------"
    putStrLn "|        Menu        |" 
    putStrLn " --------------------"
    putStrLn "(1). Adicionar Estudante"
    putStrLn "(2). Buscar Estudande por ID"
    putStrLn "(3). Atualizar Cadastro"
    putStrLn "(4). Sair"
    opcao <- readLn
    case opcao of 
        1 -> do
            novoDatabase <- adicionarStudent x
            menu novoDatabase
        2 -> do 
            filtrarStudent x 
            menu x
        3 -> do
            putStrLn "\n---------------------------------------------"
            putStrLn"          Atualizando Cadastro"
            putStrLn "---------------------------------------------"
            putStrLn "Digite o ID do estudante que deseja atualizar:"
            num <- readLn
            if alunoJaCadastrado num x
                then do
                    putStrLn "\nDigite o novo primeiro nome:"
                    novoNome <- getLine
                    putStrLn "Digite o novo sobrenome:"
                    novoSobrenome <- getLine
                    putStrLn "Digite a nova idade:"
                    novaIdade <- readLn :: IO Age
                    let novoDatabase = atualizaCadastro num (novoNome, novoSobrenome, novaIdade) x
                    putStrLn "\nCadastro atualizado!"
                    menu novoDatabase
                else do
                    putStrLn "\nID não cadastrado! Tente novamente."
                    menu x
        4 -> putStrLn "Saindo..."
        _ -> do 
            putStrLn "Opção inválida! Tente novamente"
            menu x

-- Função Main 
main :: IO()
main = do
    putStrLn "-----------------------------------------------"
    putStrLn "Sistema de Gerenciamento de Dados de Estudantes"
    putStrLn "-----------------------------------------------"
    menu initialDatabase