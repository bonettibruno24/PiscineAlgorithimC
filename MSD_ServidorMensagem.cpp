#include "pch.h"
#include "MSD_ServidorMensagem.h"
#include "IOFile.h"

bool CMSD_ServidorMensagem::GravaMensagem(const REG_MENSAGEM& regMensagem, ULONG ulPonteiro)
{
    IOFile<REG_MENSAGEM> arqMensagem(NOME_ARQUIVO_MENSAGEM);

    if (!arqMensagem.Grava(ulPonteiro, regMensagem))
        return false;

    return true;
}

bool CMSD_ServidorMensagem::LeMensagem(ULONG ulPosicao, REG_MENSAGEM& regMensagem)
{
    IOFile<REG_MENSAGEM> arqMensagem(NOME_ARQUIVO_MENSAGEM);

    if (!arqMensagem.Le(ulPosicao, regMensagem))
        return false;

    return true;
}

bool CMSD_ServidorMensagem::LeListaMensagem(std::vector<REG_MENSAGEM>& aregMensagems)
{
    IOFile<REG_MENSAGEM> arqMensagem(NOME_ARQUIVO_MENSAGEM);

    if (!arqMensagem.LeTudo(aregMensagems))
        return false;

    return true;
}