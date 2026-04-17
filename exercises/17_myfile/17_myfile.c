#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void print_elf_type(uint16_t e_type) {
  const char *type_str;
  switch (e_type) {
    // TODO: 在这里添加你的代码
    case ET_NONE: type_str = "Unknown"; break;
    case ET_REL:  type_str = "Relocatable"; break;
    case ET_EXEC: type_str = "Executable"; break;
    case ET_DYN:  type_str = "Shared Object/PIE"; break;
    case ET_CORE: type_str = "CORE (核心转储文件)"; break;
    default:      type_str = "处理器特定或未知类型"; break;
  }
  printf("ELF Type: %s (0x%x)\n", type_str, e_type);
}

int main(int argc, char *argv[]) {
  char filepath[2][256] = {
    "./17_myfile.o",
    "./17_myfile",
  };

  int fd;
  Elf64_Ehdr ehdr;

  // TODO: 在这里添加你的代码
  for (int i = 0; i < 2; i++) {
    printf("正在检查文件: %s\n", filepath[i]);

    // 以只读模式打开文件
    fd = open(filepath[i], O_RDONLY);
    if (fd < 0) {
      perror("无法打开文件");
      continue;
    }

    // 读取 ELF 头部 (位于文件最开始的部分)
    if (read(fd, &ehdr, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr)) {
      perror("读取 ELF 头部失败");
      close(fd);
      continue;
    }

    // 基础验证：检查 ELF 魔数 (Magic Number)
    // 前四个字节必须是 0x7f, 'E', 'L', 'F'
    if (memcmp(ehdr.e_ident, ELFMAG, SELFMAG) == 0) {
      print_elf_type(ehdr.e_type);
    } else {
      printf("错误: 不是一个有效的 ELF 文件。\n");
    }

    close(fd);
    printf("---------------------------\n");
  }
  
  return 0;
}
